#include <Arduino.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#define CURRENT_MEASURE_INTERVAL 1000
#define PUMP_WORK_DELAY 10000
#define PUMP_PAUSE_DELAY 20000
#define PUMP_PIN 2
#define CURR_DETECTION_THR 10

typedef enum plc_states {DRAINING, WAITING, PAUSED} plc_state_t;
typedef enum msg_types {DRAINING_MSG, WAITING_MSG, PAUSED_MSG, MEASURE_MSG} msg_types_t;
typedef enum pump_cmds {ON,OFF} pump_cmd_t;


void pump (pump_cmd_t cmd);
void sendmessage(msg_types_t msg);
void processstates(unsigned long cycletime);
void processconnections();
void wifiinit();
void initmqtt();


const char* ssid     = "iho";
const char* password = "pkjgjk_wifi";
const char* mqttServer = "192.168.1.110";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";
const char* mqttTopic = "iho-iot/2";


unsigned long currmeasurestart, drainstart, pausestart;
plc_state_t plc_state;
int current_consumption;
boolean isCurrent(void);
boolean currentdetected;
int debugcycle;

WiFiClient espClient;
PubSubClient client(espClient);


void setup(void) {
    Serial.begin(115200);
   // Serial.setDebugOutput(true);
    delay(5000);

    plc_state = WAITING;
    currmeasurestart = 0;
    drainstart = 0;
    pausestart = 0;
    currentdetected = false;
    current_consumption = 0;
    pinMode(PUMP_PIN, OUTPUT);
    debugcycle = 0;

    wifiinit();
    initmqtt();
}

void loop() {

    unsigned int cycletime = millis();
    processstates(cycletime);
  //  yield();
    processconnections();
   // yield();
    client.loop();
}

void processstates(unsigned long cycletime){

	if ( cycletime - currmeasurestart >= CURRENT_MEASURE_INTERVAL){
			currmeasurestart = cycletime;
			currentdetected = isCurrent();
			if (plc_state == DRAINING) {
			 sendmessage(MEASURE_MSG);
			}
		}

		if (plc_state == WAITING && currentdetected) {
			plc_state = DRAINING;
			sendmessage(DRAINING_MSG);
			drainstart = cycletime;
		}

		if (plc_state == DRAINING && (cycletime - drainstart >= PUMP_WORK_DELAY)){
		    plc_state = PAUSED;
		    sendmessage(PAUSED_MSG);
		    pausestart = cycletime;
			pump(OFF);
		}

		if (plc_state == PAUSED && (cycletime - pausestart >= PUMP_PAUSE_DELAY)){
			    plc_state = DRAINING;
			    sendmessage(DRAINING_MSG);
			    drainstart = cycletime;
				pump(ON);
			}

		if ( plc_state == DRAINING && !currentdetected) {
			plc_state = WAITING;
			sendmessage(WAITING_MSG);
		}
}

void pump (pump_cmd_t cmd){
	switch (cmd){
	  case ON:
		  digitalWrite(PUMP_PIN, HIGH);
		  break;
	  case OFF:
		  digitalWrite(PUMP_PIN, LOW);
		  break;

	}
}

boolean isCurrent(){
	int i; //analogRead(A0);
	debugcycle ++;
	if ( debugcycle%3 == 0 ) i = 0; else i = 100;
	if (i >= CURR_DETECTION_THR) {
		current_consumption = i;
		return true;
	} else  return false;

}

void sendmessage(msg_types_t msg){
	String mqttmsg = "{\"state\":";
	switch (msg){
	case DRAINING_MSG:
		mqttmsg += "\"drain\"}";
		break;
	case WAITING_MSG:
		mqttmsg += "\"wait\"}";
		break;
	case PAUSED_MSG:
		mqttmsg += "\"paused\"}";
		break;
	case MEASURE_MSG:
		mqttmsg += "\"drain\",\"amp\":"+String(current_consumption)+"}";
		break;

	}
  client.publish(mqttTopic,mqttmsg.c_str());

}

void wifiinit(){
	  WiFi.mode(WIFI_STA);
	  WiFi.begin(ssid, password);

}


void initmqtt(){

  client.setServer(mqttServer, mqttPort);
  client.connect("ESP32Client", mqttUser, mqttPassword );

}


void processconnections(){
	if (WiFi.status() != WL_CONNECTED) wifiinit();
	if (!client.connected()) initmqtt();
}

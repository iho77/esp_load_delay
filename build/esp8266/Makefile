ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/user-main.cpp.o \

PLATFORM_CORE_OBJS = \
	core/abi.cpp.o \
	core/base64.cpp.o \
	core/cbuf.cpp.o \
	core/cont.S.o \
	core/cont_util.c.o \
	core/core_esp8266_eboot_command.c.o \
	core/core_esp8266_flash_utils.c.o \
	core/core_esp8266_i2s.c.o \
	core/core_esp8266_main.cpp.o \
	core/core_esp8266_noniso.c.o \
	core/core_esp8266_phy.c.o \
	core/core_esp8266_postmortem.c.o \
	core/core_esp8266_si2c.c.o \
	core/core_esp8266_timer.c.o \
	core/core_esp8266_wiring.c.o \
	core/core_esp8266_wiring_analog.c.o \
	core/core_esp8266_wiring_digital.c.o \
	core/core_esp8266_wiring_pulse.c.o \
	core/core_esp8266_wiring_pwm.c.o \
	core/core_esp8266_wiring_shift.c.o \
	core/debug.cpp.o \
	core/Esp.cpp.o \
	core/FS.cpp.o \
	core/FunctionalInterrupt.cpp.o \
	core/HardwareSerial.cpp.o \
	core/heap.c.o \
	core/IPAddress.cpp.o \
	core/libb64/cdecode.c.o \
	core/libb64/cencode.c.o \
	core/libc_replacements.c.o \
	core/MD5Builder.cpp.o \
	core/pgmspace.cpp.o \
	core/Print.cpp.o \
	core/Schedule.cpp.o \
	core/spiffs/spiffs_cache.c.o \
	core/spiffs/spiffs_check.c.o \
	core/spiffs/spiffs_gc.c.o \
	core/spiffs/spiffs_hydrogen.c.o \
	core/spiffs/spiffs_nucleus.c.o \
	core/spiffs_api.cpp.o \
	core/spiffs_hal.cpp.o \
	core/Stream.cpp.o \
	core/StreamString.cpp.o \
	core/time.c.o \
	core/Tone.cpp.o \
	core/uart.c.o \
	core/umm_malloc/umm_malloc.c.o \
	core/Updater.cpp.o \
	core/WMath.cpp.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.o \
	libraries/ESP8266WiFi/src/ESP8266WiFiAP.cpp.o \
	libraries/ESP8266WiFi/src/ESP8266WiFiGeneric.cpp.o \
	libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.o \
	libraries/ESP8266WiFi/src/ESP8266WiFiScan.cpp.o \
	libraries/ESP8266WiFi/src/ESP8266WiFiSTA.cpp.o \
	libraries/ESP8266WiFi/src/WiFiClient.cpp.o \
	libraries/ESP8266WiFi/src/WiFiClientSecure.cpp.o \
	libraries/ESP8266WiFi/src/WiFiServer.cpp.o \
	libraries/ESP8266WiFi/src/WiFiUdp.cpp.o \
	libraries/PubSubClient/2.6.0/src/PubSubClient.cpp.o \

TARGETS = \
	esp_pump_timer.hex \

all: $(TARGETS)

esp_pump_timer.hex: esp_pump_timer.elf
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/esptool/0.4.12/esptool" -eo "C:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/bootloaders/eboot/eboot.elf" -bo "./esp_pump_timer.bin" -bm dio -bf 40 -bz 1M -bs .text -bp 4096 -ec -eo "./esp_pump_timer.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec

esp_pump_timer.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -g -w -Os -nostdlib -Wl,--no-check-sections -u call_user_start -u _printf_float -u _scanf_float -Wl,-static "-LC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lib" "-LC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/ld" "-LC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/lib" "-Teagle.flash.1m512.ld" -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,spi_flash_read  -o "./esp_pump_timer.elf" -Wl,--start-group $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./arduino.ar" -lhal -lphy -lpp -lnet80211 -llwip_gcc -lwpa -lcrypto -lmain -lwps -laxtls -lespnow -lsmartconfig -lairkiss -lmesh -lwpa2 -lstdc++ -lm -lc -lgcc -Wl,--end-group  "-L."

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-size" -A "./esp_pump_timer.elf"

project/user-main.cpp.o: ../../user-main.cpp project/user-main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

project/user-main.cpp.d: ;

-include project/user-main.cpp.d 


core/abi.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/base64.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/base64.cpp core/base64.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/base64.cpp.d: ;

-include core/base64.cpp.d

core/cbuf.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/cbuf.cpp core/cbuf.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/cbuf.cpp.d: ;

-include core/cbuf.cpp.d

core/cont.S.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/cont.S
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -g -x assembler-with-cpp -MMD -mlongcalls -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/cont_util.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/cont_util.c core/cont_util.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/cont_util.c.d: ;

-include core/cont_util.c.d

core/core_esp8266_eboot_command.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_eboot_command.c core/core_esp8266_eboot_command.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_eboot_command.c.d: ;

-include core/core_esp8266_eboot_command.c.d

core/core_esp8266_flash_utils.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_flash_utils.c core/core_esp8266_flash_utils.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_flash_utils.c.d: ;

-include core/core_esp8266_flash_utils.c.d

core/core_esp8266_i2s.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_i2s.c core/core_esp8266_i2s.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_i2s.c.d: ;

-include core/core_esp8266_i2s.c.d

core/core_esp8266_main.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_main.cpp core/core_esp8266_main.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/core_esp8266_main.cpp.d: ;

-include core/core_esp8266_main.cpp.d

core/core_esp8266_noniso.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_noniso.c core/core_esp8266_noniso.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_noniso.c.d: ;

-include core/core_esp8266_noniso.c.d

core/core_esp8266_phy.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_phy.c core/core_esp8266_phy.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_phy.c.d: ;

-include core/core_esp8266_phy.c.d

core/core_esp8266_postmortem.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_postmortem.c core/core_esp8266_postmortem.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_postmortem.c.d: ;

-include core/core_esp8266_postmortem.c.d

core/core_esp8266_si2c.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_si2c.c core/core_esp8266_si2c.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_si2c.c.d: ;

-include core/core_esp8266_si2c.c.d

core/core_esp8266_timer.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_timer.c core/core_esp8266_timer.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_timer.c.d: ;

-include core/core_esp8266_timer.c.d

core/core_esp8266_wiring.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_wiring.c core/core_esp8266_wiring.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_wiring.c.d: ;

-include core/core_esp8266_wiring.c.d

core/core_esp8266_wiring_analog.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_wiring_analog.c core/core_esp8266_wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_wiring_analog.c.d: ;

-include core/core_esp8266_wiring_analog.c.d

core/core_esp8266_wiring_digital.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_wiring_digital.c core/core_esp8266_wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_wiring_digital.c.d: ;

-include core/core_esp8266_wiring_digital.c.d

core/core_esp8266_wiring_pulse.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_wiring_pulse.c core/core_esp8266_wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_wiring_pulse.c.d: ;

-include core/core_esp8266_wiring_pulse.c.d

core/core_esp8266_wiring_pwm.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_wiring_pwm.c core/core_esp8266_wiring_pwm.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_wiring_pwm.c.d: ;

-include core/core_esp8266_wiring_pwm.c.d

core/core_esp8266_wiring_shift.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/core_esp8266_wiring_shift.c core/core_esp8266_wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/core_esp8266_wiring_shift.c.d: ;

-include core/core_esp8266_wiring_shift.c.d

core/debug.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/debug.cpp core/debug.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/debug.cpp.d: ;

-include core/debug.cpp.d

core/Esp.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/Esp.cpp core/Esp.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/Esp.cpp.d: ;

-include core/Esp.cpp.d

core/FS.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/FS.cpp core/FS.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/FS.cpp.d: ;

-include core/FS.cpp.d

core/FunctionalInterrupt.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/FunctionalInterrupt.cpp core/FunctionalInterrupt.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/FunctionalInterrupt.cpp.d: ;

-include core/FunctionalInterrupt.cpp.d

core/HardwareSerial.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/heap.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/heap.c core/heap.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/heap.c.d: ;

-include core/heap.c.d

core/IPAddress.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/libb64/cdecode.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/libb64/cdecode.c core/libb64/cdecode.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/libb64/cdecode.c.d: ;

-include core/libb64/cdecode.c.d

core/libb64/cencode.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/libb64/cencode.c core/libb64/cencode.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/libb64/cencode.c.d: ;

-include core/libb64/cencode.c.d

core/libc_replacements.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/libc_replacements.c core/libc_replacements.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/libc_replacements.c.d: ;

-include core/libc_replacements.c.d

core/MD5Builder.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/MD5Builder.cpp core/MD5Builder.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/MD5Builder.cpp.d: ;

-include core/MD5Builder.cpp.d

core/pgmspace.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/pgmspace.cpp core/pgmspace.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/pgmspace.cpp.d: ;

-include core/pgmspace.cpp.d

core/Print.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/Schedule.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/Schedule.cpp core/Schedule.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/Schedule.cpp.d: ;

-include core/Schedule.cpp.d

core/spiffs/spiffs_cache.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs/spiffs_cache.c core/spiffs/spiffs_cache.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/spiffs/spiffs_cache.c.d: ;

-include core/spiffs/spiffs_cache.c.d

core/spiffs/spiffs_check.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs/spiffs_check.c core/spiffs/spiffs_check.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/spiffs/spiffs_check.c.d: ;

-include core/spiffs/spiffs_check.c.d

core/spiffs/spiffs_gc.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs/spiffs_gc.c core/spiffs/spiffs_gc.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/spiffs/spiffs_gc.c.d: ;

-include core/spiffs/spiffs_gc.c.d

core/spiffs/spiffs_hydrogen.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs/spiffs_hydrogen.c core/spiffs/spiffs_hydrogen.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/spiffs/spiffs_hydrogen.c.d: ;

-include core/spiffs/spiffs_hydrogen.c.d

core/spiffs/spiffs_nucleus.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs/spiffs_nucleus.c core/spiffs/spiffs_nucleus.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/spiffs/spiffs_nucleus.c.d: ;

-include core/spiffs/spiffs_nucleus.c.d

core/spiffs_api.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs_api.cpp core/spiffs_api.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/spiffs_api.cpp.d: ;

-include core/spiffs_api.cpp.d

core/spiffs_hal.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/spiffs_hal.cpp core/spiffs_hal.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/spiffs_hal.cpp.d: ;

-include core/spiffs_hal.cpp.d

core/Stream.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/StreamString.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/StreamString.cpp core/StreamString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/StreamString.cpp.d: ;

-include core/StreamString.cpp.d

core/time.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/time.c core/time.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/time.c.d: ;

-include core/time.c.d

core/Tone.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/uart.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/uart.c core/uart.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/uart.c.d: ;

-include core/uart.c.d

core/umm_malloc/umm_malloc.c.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/umm_malloc/umm_malloc.c core/umm_malloc/umm_malloc.c.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"
	
core/umm_malloc/umm_malloc.c.d: ;

-include core/umm_malloc/umm_malloc.c.d

core/Updater.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/Updater.cpp core/Updater.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/Updater.cpp.d: ;

-include core/Updater.cpp.d

core/WMath.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WString.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "./arduino.ar" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/ESP8266WiFi.cpp libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.d: ;

-include libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.d

libraries/ESP8266WiFi/src/ESP8266WiFiAP.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/ESP8266WiFiAP.cpp libraries/ESP8266WiFi/src/ESP8266WiFiAP.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/ESP8266WiFiAP.cpp.d: ;

-include libraries/ESP8266WiFi/src/ESP8266WiFiAP.cpp.d

libraries/ESP8266WiFi/src/ESP8266WiFiGeneric.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/ESP8266WiFiGeneric.cpp libraries/ESP8266WiFi/src/ESP8266WiFiGeneric.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/ESP8266WiFiGeneric.cpp.d: ;

-include libraries/ESP8266WiFi/src/ESP8266WiFiGeneric.cpp.d

libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.d: ;

-include libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.d

libraries/ESP8266WiFi/src/ESP8266WiFiScan.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/ESP8266WiFiScan.cpp libraries/ESP8266WiFi/src/ESP8266WiFiScan.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/ESP8266WiFiScan.cpp.d: ;

-include libraries/ESP8266WiFi/src/ESP8266WiFiScan.cpp.d

libraries/ESP8266WiFi/src/ESP8266WiFiSTA.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/ESP8266WiFiSTA.cpp libraries/ESP8266WiFi/src/ESP8266WiFiSTA.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/ESP8266WiFiSTA.cpp.d: ;

-include libraries/ESP8266WiFi/src/ESP8266WiFiSTA.cpp.d

libraries/ESP8266WiFi/src/WiFiClient.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/WiFiClient.cpp libraries/ESP8266WiFi/src/WiFiClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/WiFiClient.cpp.d: ;

-include libraries/ESP8266WiFi/src/WiFiClient.cpp.d

libraries/ESP8266WiFi/src/WiFiClientSecure.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/WiFiClientSecure.cpp libraries/ESP8266WiFi/src/WiFiClientSecure.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/WiFiClientSecure.cpp.d: ;

-include libraries/ESP8266WiFi/src/WiFiClientSecure.cpp.d

libraries/ESP8266WiFi/src/WiFiServer.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/WiFiServer.cpp libraries/ESP8266WiFi/src/WiFiServer.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/WiFiServer.cpp.d: ;

-include libraries/ESP8266WiFi/src/WiFiServer.cpp.d

libraries/ESP8266WiFi/src/WiFiUdp.cpp.o: C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src/WiFiUdp.cpp libraries/ESP8266WiFi/src/WiFiUdp.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/ESP8266WiFi/src/WiFiUdp.cpp.d: ;

-include libraries/ESP8266WiFi/src/WiFiUdp.cpp.d

libraries/PubSubClient/2.6.0/src/PubSubClient.cpp.o: C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src/PubSubClient.cpp libraries/PubSubClient/2.6.0/src/PubSubClient.cpp.d
	@$(call mymkdir,$(dir $@))
	"C:/Users/iho/.arduinocdt/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/lwip/include" "-IC:\Users\iho\.arduinocdt\packages\esp8266\hardware\esp8266\2.4.0-rc2/tools/sdk/libc/xtensa-lx106-elf/include" "-I./core" -c -w -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC   -DARDUINO=10608 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="ESP8266_ESP01"  -DESP8266 -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/cores/esp8266" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/variants/generic" -I"C:/Users/iho/.arduinocdt/packages/esp8266/hardware/esp8266/2.4.0-rc2/libraries/ESP8266WiFi/src" -I"C:/Users/iho/.arduinocdt/libraries/PubSubClient/2.6.0/src" "$<" -o "$@"

libraries/PubSubClient/2.6.0/src/PubSubClient.cpp.d: ;

-include libraries/PubSubClient/2.6.0/src/PubSubClient.cpp.d


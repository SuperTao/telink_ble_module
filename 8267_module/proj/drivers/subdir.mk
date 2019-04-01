################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../proj/drivers/audio.c \
../proj/drivers/battery.c \
../proj/drivers/emi.c \
../proj/drivers/flash.c \
../proj/drivers/i2c.c \
../proj/drivers/keyboard.c \
../proj/drivers/rf_pa.c \
../proj/drivers/spi.c \
../proj/drivers/uart.c \
../proj/drivers/usb.c \
../proj/drivers/usb_uart.c \
../proj/drivers/usbdesc.c \
../proj/drivers/usbhw.c 

OBJS += \
./proj/drivers/audio.o \
./proj/drivers/battery.o \
./proj/drivers/emi.o \
./proj/drivers/flash.o \
./proj/drivers/i2c.o \
./proj/drivers/keyboard.o \
./proj/drivers/rf_pa.o \
./proj/drivers/spi.o \
./proj/drivers/uart.o \
./proj/drivers/usb.o \
./proj/drivers/usb_uart.o \
./proj/drivers/usbdesc.o \
./proj/drivers/usbhw.o 


# Each subdirectory must supply rules for building sources it contributes
proj/drivers/%.o: ../proj/drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj\mcu_spec" -I../proj/mcu -D__PROJECT_8267_MODULE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



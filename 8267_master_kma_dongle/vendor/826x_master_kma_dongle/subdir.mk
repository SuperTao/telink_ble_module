################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/826x_master_kma_dongle/app.c \
../vendor/826x_master_kma_dongle/app_att.c \
../vendor/826x_master_kma_dongle/app_ota.c \
../vendor/826x_master_kma_dongle/app_pair.c \
../vendor/826x_master_kma_dongle/audio_buffer.c \
../vendor/826x_master_kma_dongle/button.c \
../vendor/826x_master_kma_dongle/main.c 

OBJS += \
./vendor/826x_master_kma_dongle/app.o \
./vendor/826x_master_kma_dongle/app_att.o \
./vendor/826x_master_kma_dongle/app_ota.o \
./vendor/826x_master_kma_dongle/app_pair.o \
./vendor/826x_master_kma_dongle/audio_buffer.o \
./vendor/826x_master_kma_dongle/button.o \
./vendor/826x_master_kma_dongle/main.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/826x_master_kma_dongle/%.o: ../vendor/826x_master_kma_dongle/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I../proj/mcu_spec -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\vendor\common" -I../proj/mcu -D__PROJECT_8267_MASTER_KMA_DONGLE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



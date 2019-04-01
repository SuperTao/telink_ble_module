################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/826x_ble_remote/app.c \
../vendor/826x_ble_remote/app_att.c \
../vendor/826x_ble_remote/main.c \
../vendor/826x_ble_remote/rc_ir.c 

OBJS += \
./vendor/826x_ble_remote/app.o \
./vendor/826x_ble_remote/app_att.o \
./vendor/826x_ble_remote/main.o \
./vendor/826x_ble_remote/rc_ir.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/826x_ble_remote/%.o: ../vendor/826x_ble_remote/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj\mcu" -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj\mcu_spec" -D__PROJECT_8267_BLE_REMOTE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



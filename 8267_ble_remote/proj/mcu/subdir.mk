################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../proj/mcu/analog.c \
../proj/mcu/anareg.c \
../proj/mcu/audhw.c \
../proj/mcu/clock.c \
../proj/mcu/cpu.c \
../proj/mcu/otp.c \
../proj/mcu/putchar.c \
../proj/mcu/random.c \
../proj/mcu/register.c \
../proj/mcu/swire.c 

OBJS += \
./proj/mcu/analog.o \
./proj/mcu/anareg.o \
./proj/mcu/audhw.o \
./proj/mcu/clock.o \
./proj/mcu/cpu.o \
./proj/mcu/otp.o \
./proj/mcu/putchar.o \
./proj/mcu/random.o \
./proj/mcu/register.o \
./proj/mcu/swire.o 


# Each subdirectory must supply rules for building sources it contributes
proj/mcu/%.o: ../proj/mcu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj\mcu" -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj\mcu_spec" -D__PROJECT_8267_BLE_REMOTE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



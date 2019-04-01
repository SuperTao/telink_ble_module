################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../proj/common/breakpoint.c \
../proj/common/compatibility.c \
../proj/common/log.c \
../proj/common/selection_sort.c \
../proj/common/string.c \
../proj/common/utility.c 

OBJS += \
./proj/common/breakpoint.o \
./proj/common/compatibility.o \
./proj/common/log.o \
./proj/common/selection_sort.o \
./proj/common/string.o \
./proj/common/utility.o 


# Each subdirectory must supply rules for building sources it contributes
proj/common/%.o: ../proj/common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj\mcu_spec" -I../proj/mcu -D__PROJECT_8267_MODULE__=1 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



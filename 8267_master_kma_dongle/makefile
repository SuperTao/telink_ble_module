################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include vendor/common/subdir.mk
-include vendor/826x_master_kma_dongle/subdir.mk
-include proj/mcu_spec/subdir.mk
-include proj/mcu/subdir.mk
-include proj/drivers/subdir.mk
-include proj/common/subdir.mk
-include proj/app/subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LST += \
8267_master_kma_dongle.lst \

FLASH_IMAGE += \
8267_master_kma_dongle.bin \

SIZEDUMMY += \
sizedummy \


# All Target
all: pre-build main-build

# Main-build Target
main-build: ble_sdk_lt_app_lic.elf secondary-outputs

# Tool invocations
ble_sdk_lt_app_lic.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: TC32 C Linker'
	tc32-elf-ld --gc-sections -L"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic\proj_lib" -T ../boot.link -o"ble_sdk_lt_app_lic.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

8267_master_kma_dongle.lst: ble_sdk_lt_app_lic.elf
	@echo 'Invoking: TC32 Create Extended Listing'
	tc32-elf-objdump -x -D -l -S ble_sdk_lt_app_lic.elf  >"8267_master_kma_dongle.lst"
	@echo 'Finished building: $@'
	@echo ' '

8267_master_kma_dongle.bin: ble_sdk_lt_app_lic.elf
	@echo 'Create Flash image (binary format)'
	tc32-elf-objcopy -O binary ble_sdk_lt_app_lic.elf  "8267_master_kma_dongle.bin"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ble_sdk_lt_app_lic.elf
	@echo 'Invoking: Print Size'
	tc32-elf-size -t ble_sdk_lt_app_lic.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(FLASH_IMAGE)$(ELFS)$(LST)$(SIZEDUMMY) ble_sdk_lt_app_lic.elf
	-@echo ' '

pre-build:
	-"E:\Telink_BLE\826x module sdk\826x ble sdk release collect\telink_ble_sdk_release_v3.2.0_20170906\ble_sdk_release_lic/getver.sh"
	-@echo ' '

secondary-outputs: $(LST) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets

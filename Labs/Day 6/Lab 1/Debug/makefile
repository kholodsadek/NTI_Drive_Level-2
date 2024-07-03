################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 04-MCAL/01-DIO/subdir.mk
-include 03-HAL/02-SEVEN_SEGMENT/subdir.mk
-include 03-HAL/01-LED/subdir.mk
-include 02-APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NTI_Lab1_day6_Bush_Button.lss \

FLASH_IMAGE += \
NTI_Lab1_day6_Bush_Button.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_Lab1_day6_Bush_Button.elf secondary-outputs

# Tool invocations
NTI_Lab1_day6_Bush_Button.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_Lab1_day6_Bush_Button.map -mmcu=atmega32 -o "NTI_Lab1_day6_Bush_Button.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_Lab1_day6_Bush_Button.lss: NTI_Lab1_day6_Bush_Button.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_Lab1_day6_Bush_Button.elf  >"NTI_Lab1_day6_Bush_Button.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_Lab1_day6_Bush_Button.hex: NTI_Lab1_day6_Bush_Button.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_Lab1_day6_Bush_Button.elf  "NTI_Lab1_day6_Bush_Button.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_Lab1_day6_Bush_Button.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_Lab1_day6_Bush_Button.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_Lab1_day6_Bush_Button.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

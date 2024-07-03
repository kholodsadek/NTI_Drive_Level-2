################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 04-MCAL/03-ADC/subdir.mk
-include 04-MCAL/02-EXTI/subdir.mk
-include 04-MCAL/01-DIO/subdir.mk
-include 03-HAL/09-LDR/subdir.mk
-include 03-HAL/08-POT/subdir.mk
-include 03-HAL/07-LM35/subdir.mk
-include 03-HAL/06-DC_MOTOR/subdir.mk
-include 03-HAL/05-KPD/subdir.mk
-include 03-HAL/04-CLCD/subdir.mk
-include 03-HAL/03-BUSH_BUTTON/subdir.mk
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
NTI_Project_Calculator_System.lss \

FLASH_IMAGE += \
NTI_Project_Calculator_System.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_Project_Calculator_System.elf secondary-outputs

# Tool invocations
NTI_Project_Calculator_System.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_Project_Calculator_System.map -mmcu=atmega32 -o "NTI_Project_Calculator_System.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_Project_Calculator_System.lss: NTI_Project_Calculator_System.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_Project_Calculator_System.elf  >"NTI_Project_Calculator_System.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_Project_Calculator_System.hex: NTI_Project_Calculator_System.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_Project_Calculator_System.elf  "NTI_Project_Calculator_System.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_Project_Calculator_System.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_Project_Calculator_System.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_Project_Calculator_System.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 04-MCAL/02-EXTI/subdir.mk
-include 04-MCAL/01-DIO/subdir.mk
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
NTI_Control_DC_Motor_by_EXTI_Task_day12.lss \

FLASH_IMAGE += \
NTI_Control_DC_Motor_by_EXTI_Task_day12.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_Control_DC_Motor_by_EXTI_Task_day12.elf secondary-outputs

# Tool invocations
NTI_Control_DC_Motor_by_EXTI_Task_day12.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_Control_DC_Motor_by_EXTI_Task_day12.map -mmcu=atmega32 -o "NTI_Control_DC_Motor_by_EXTI_Task_day12.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_Control_DC_Motor_by_EXTI_Task_day12.lss: NTI_Control_DC_Motor_by_EXTI_Task_day12.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_Control_DC_Motor_by_EXTI_Task_day12.elf  >"NTI_Control_DC_Motor_by_EXTI_Task_day12.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_Control_DC_Motor_by_EXTI_Task_day12.hex: NTI_Control_DC_Motor_by_EXTI_Task_day12.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_Control_DC_Motor_by_EXTI_Task_day12.elf  "NTI_Control_DC_Motor_by_EXTI_Task_day12.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_Control_DC_Motor_by_EXTI_Task_day12.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_Control_DC_Motor_by_EXTI_Task_day12.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_Control_DC_Motor_by_EXTI_Task_day12.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

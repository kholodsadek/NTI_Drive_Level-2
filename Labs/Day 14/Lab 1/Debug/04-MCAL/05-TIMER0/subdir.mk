################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../04-MCAL/05-TIMER0/TIMER0_Program.c 

OBJS += \
./04-MCAL/05-TIMER0/TIMER0_Program.o 

C_DEPS += \
./04-MCAL/05-TIMER0/TIMER0_Program.d 


# Each subdirectory must supply rules for building sources it contributes
04-MCAL/05-TIMER0/%.o: ../04-MCAL/05-TIMER0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



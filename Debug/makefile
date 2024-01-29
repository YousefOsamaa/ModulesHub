################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TMU/subdir.mk
-include MCAL/USART/subdir.mk
-include MCAL/Timers/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/SREG/subdir.mk
-include MCAL/PWM/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SW/subdir.mk
-include HAL/Relay/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/ICU/subdir.mk
-include HAL/Hexadecoder/subdir.mk
-include HAL/Buzzer/subdir.mk
-include APP/subdir.mk
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
ModuleHub.lss \

FLASH_IMAGE += \
ModuleHub.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ModuleHub.elf secondary-outputs

# Tool invocations
ModuleHub.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ModuleHub.map -mmcu=atmega32 -o "ModuleHub.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ModuleHub.lss: ModuleHub.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ModuleHub.elf  >"ModuleHub.lss"
	@echo 'Finished building: $@'
	@echo ' '

ModuleHub.hex: ModuleHub.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ModuleHub.elf  "ModuleHub.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ModuleHub.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ModuleHub.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ModuleHub.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

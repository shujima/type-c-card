################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
MoonRiverProject_L-chika.hex \

SECONDARY_LIST += \
MoonRiverProject_L-chika.lst \

SECONDARY_SIZE += \
MoonRiverProject_L-chika.siz \


# All Target
all: MoonRiverProject_L-chika.elf secondary-outputs

# Tool invocations
MoonRiverProject_L-chika.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_L-chika\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"MoonRiverProject_L-chika.map" --specs=nano.specs --specs=nosys.specs -o "MoonRiverProject_L-chika.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
MoonRiverProject_L-chika.hex: MoonRiverProject_L-chika.elf
	@	riscv-none-embed-objcopy -O ihex "MoonRiverProject_L-chika.elf"  "MoonRiverProject_L-chika.hex"
	@	@
MoonRiverProject_L-chika.lst: MoonRiverProject_L-chika.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "MoonRiverProject_L-chika.elf" > "MoonRiverProject_L-chika.lst"
	@	@
MoonRiverProject_L-chika.siz: MoonRiverProject_L-chika.elf
	@	riscv-none-embed-size --format=berkeley "MoonRiverProject_L-chika.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) MoonRiverProject_L-chika.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets

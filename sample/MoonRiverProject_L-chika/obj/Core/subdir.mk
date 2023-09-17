################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/core_riscv.o: C:/Develop/Hobby_ECAD/type-c-card/sample/MoonRiverProject_L-chika/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_L-chika\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_L-chika\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_L-chika\User" -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_L-chika\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


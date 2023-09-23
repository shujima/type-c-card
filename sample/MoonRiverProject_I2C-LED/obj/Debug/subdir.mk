################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Debug/debug.c 

OBJS += \
./Debug/debug.o 

C_DEPS += \
./Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
Debug/debug.o: C:/Develop/Hobby_ECAD/type-c-card/sample/MoonRiverProject_I2C-LED/Debug/debug.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/I2C.c \
../User/I2C_LED_IS31FL3731.c \
../User/TC_LED_Matrix.c \
../User/ch32v20x_it.c \
../User/main.c \
../User/system_ch32v20x.c 

OBJS += \
./User/I2C.o \
./User/I2C_LED_IS31FL3731.o \
./User/TC_LED_Matrix.o \
./User/ch32v20x_it.o \
./User/main.o \
./User/system_ch32v20x.o 

C_DEPS += \
./User/I2C.d \
./User/I2C_LED_IS31FL3731.d \
./User/TC_LED_Matrix.d \
./User/ch32v20x_it.d \
./User/main.d \
./User/system_ch32v20x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


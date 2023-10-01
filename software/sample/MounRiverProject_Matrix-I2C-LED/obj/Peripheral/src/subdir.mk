################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/ch32v20x_adc.c \
../Peripheral/src/ch32v20x_bkp.c \
../Peripheral/src/ch32v20x_can.c \
../Peripheral/src/ch32v20x_crc.c \
../Peripheral/src/ch32v20x_dbgmcu.c \
../Peripheral/src/ch32v20x_dma.c \
../Peripheral/src/ch32v20x_exti.c \
../Peripheral/src/ch32v20x_flash.c \
../Peripheral/src/ch32v20x_gpio.c \
../Peripheral/src/ch32v20x_i2c.c \
../Peripheral/src/ch32v20x_iwdg.c \
../Peripheral/src/ch32v20x_misc.c \
../Peripheral/src/ch32v20x_opa.c \
../Peripheral/src/ch32v20x_pwr.c \
../Peripheral/src/ch32v20x_rcc.c \
../Peripheral/src/ch32v20x_rtc.c \
../Peripheral/src/ch32v20x_spi.c \
../Peripheral/src/ch32v20x_tim.c \
../Peripheral/src/ch32v20x_usart.c \
../Peripheral/src/ch32v20x_wwdg.c 

OBJS += \
./Peripheral/src/ch32v20x_adc.o \
./Peripheral/src/ch32v20x_bkp.o \
./Peripheral/src/ch32v20x_can.o \
./Peripheral/src/ch32v20x_crc.o \
./Peripheral/src/ch32v20x_dbgmcu.o \
./Peripheral/src/ch32v20x_dma.o \
./Peripheral/src/ch32v20x_exti.o \
./Peripheral/src/ch32v20x_flash.o \
./Peripheral/src/ch32v20x_gpio.o \
./Peripheral/src/ch32v20x_i2c.o \
./Peripheral/src/ch32v20x_iwdg.o \
./Peripheral/src/ch32v20x_misc.o \
./Peripheral/src/ch32v20x_opa.o \
./Peripheral/src/ch32v20x_pwr.o \
./Peripheral/src/ch32v20x_rcc.o \
./Peripheral/src/ch32v20x_rtc.o \
./Peripheral/src/ch32v20x_spi.o \
./Peripheral/src/ch32v20x_tim.o \
./Peripheral/src/ch32v20x_usart.o \
./Peripheral/src/ch32v20x_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32v20x_adc.d \
./Peripheral/src/ch32v20x_bkp.d \
./Peripheral/src/ch32v20x_can.d \
./Peripheral/src/ch32v20x_crc.d \
./Peripheral/src/ch32v20x_dbgmcu.d \
./Peripheral/src/ch32v20x_dma.d \
./Peripheral/src/ch32v20x_exti.d \
./Peripheral/src/ch32v20x_flash.d \
./Peripheral/src/ch32v20x_gpio.d \
./Peripheral/src/ch32v20x_i2c.d \
./Peripheral/src/ch32v20x_iwdg.d \
./Peripheral/src/ch32v20x_misc.d \
./Peripheral/src/ch32v20x_opa.d \
./Peripheral/src/ch32v20x_pwr.d \
./Peripheral/src/ch32v20x_rcc.d \
./Peripheral/src/ch32v20x_rtc.d \
./Peripheral/src/ch32v20x_spi.d \
./Peripheral/src/ch32v20x_tim.d \
./Peripheral/src/ch32v20x_usart.d \
./Peripheral/src/ch32v20x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32v20x_adc.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_bkp.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_bkp.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_can.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_can.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_crc.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_crc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_dbgmcu.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_dbgmcu.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_dma.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_dma.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_exti.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_flash.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_gpio.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_i2c.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_i2c.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_iwdg.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_iwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_misc.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_misc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_opa.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_opa.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_pwr.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_rcc.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_rcc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_rtc.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_rtc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_spi.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_tim.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_tim.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_usart.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_usart.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_wwdg.o: C:/Develop/Hobby_ECAD/type-c-card/software/sample/MoonRiverProject_I2C-LED/Peripheral/src/ch32v20x_wwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Debug" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Core" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\User" -I"C:\Develop\Hobby_ECAD\type-c-card\software\sample\MoonRiverProject_I2C-LED\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


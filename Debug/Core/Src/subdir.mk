################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/i2c-lcd.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/timer.c 

OBJS += \
./Core/Src/i2c-lcd.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/timer.o 

C_DEPS += \
./Core/Src/i2c-lcd.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:/coding/airsoft/Veliavu_taimeris_v2.0/Core/Inc" -I"D:/coding/airsoft/Veliavu_taimeris_v2.0/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/coding/airsoft/Veliavu_taimeris_v2.0/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"D:/coding/airsoft/Veliavu_taimeris_v2.0/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/coding/airsoft/Veliavu_taimeris_v2.0/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



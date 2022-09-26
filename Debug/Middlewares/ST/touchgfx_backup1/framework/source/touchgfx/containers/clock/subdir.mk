################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AbstractClock.cpp \
../Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AnalogClock.cpp \
../Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/DigitalClock.cpp 

OBJS += \
./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AbstractClock.o \
./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AnalogClock.o \
./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/DigitalClock.o 

CPP_DEPS += \
./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AbstractClock.d \
./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AnalogClock.d \
./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/DigitalClock.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/%.o Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/%.su: ../Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/%.cpp Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-touchgfx_backup1-2f-framework-2f-source-2f-touchgfx-2f-containers-2f-clock

clean-Middlewares-2f-ST-2f-touchgfx_backup1-2f-framework-2f-source-2f-touchgfx-2f-containers-2f-clock:
	-$(RM) ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AbstractClock.d ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AbstractClock.o ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AbstractClock.su ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AnalogClock.d ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AnalogClock.o ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/AnalogClock.su ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/DigitalClock.d ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/DigitalClock.o ./Middlewares/ST/touchgfx_backup1/framework/source/touchgfx/containers/clock/DigitalClock.su

.PHONY: clean-Middlewares-2f-ST-2f-touchgfx_backup1-2f-framework-2f-source-2f-touchgfx-2f-containers-2f-clock


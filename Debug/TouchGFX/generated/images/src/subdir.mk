################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/image_race1.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/image_race1.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/image_race1.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/BitmapDatabase.o: ../TouchGFX/generated/images/src/BitmapDatabase.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../FATFS/Target -I../FATFS/App -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"TouchGFX/generated/images/src/BitmapDatabase.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TouchGFX/generated/images/src/image_race1.o: ../TouchGFX/generated/images/src/image_race1.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../FATFS/Target -I../FATFS/App -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"TouchGFX/generated/images/src/image_race1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


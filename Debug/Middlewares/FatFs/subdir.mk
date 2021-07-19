################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/diskio.c \
C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/ff.c \
C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/option/syscall.c 

C_DEPS += \
./Middlewares/FatFs/diskio.d \
./Middlewares/FatFs/ff.d \
./Middlewares/FatFs/ff_gen_drv.d \
./Middlewares/FatFs/syscall.d 

OBJS += \
./Middlewares/FatFs/diskio.o \
./Middlewares/FatFs/ff.o \
./Middlewares/FatFs/ff_gen_drv.o \
./Middlewares/FatFs/syscall.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FatFs/diskio.o: C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/diskio.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../FATFS/Target -I../FATFS/App -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/ff.o: C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/ff.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../FATFS/Target -I../FATFS/App -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/ff_gen_drv.o: C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../FATFS/Target -I../FATFS/App -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/ff_gen_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/syscall.o: C:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src/option/syscall.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../FATFS/Target -I../FATFS/App -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Middlewares/Third_Party/FatFs/src -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Ben/STM32Cube/Repository/STM32Cube_FW_F4_V1.26.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/FatFs/syscall.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


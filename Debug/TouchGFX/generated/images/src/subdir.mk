################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/image_blue_100x100.cpp \
../TouchGFX/generated/images/src/image_gray_100x100png.cpp \
../TouchGFX/generated/images/src/image_green_100x100.cpp \
../TouchGFX/generated/images/src/image_indBatt.cpp \
../TouchGFX/generated/images/src/image_indDTC.cpp \
../TouchGFX/generated/images/src/image_indECT.cpp \
../TouchGFX/generated/images/src/image_indFuel.cpp \
../TouchGFX/generated/images/src/image_indHigh.cpp \
../TouchGFX/generated/images/src/image_indLeft.cpp \
../TouchGFX/generated/images/src/image_indLow.cpp \
../TouchGFX/generated/images/src/image_indOil.cpp \
../TouchGFX/generated/images/src/image_indPark.cpp \
../TouchGFX/generated/images/src/image_indRight.cpp \
../TouchGFX/generated/images/src/image_needel.cpp \
../TouchGFX/generated/images/src/image_race_dash.cpp \
../TouchGFX/generated/images/src/image_red_100x100.cpp \
../TouchGFX/generated/images/src/image_speeduino1.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/image_blue_100x100.o \
./TouchGFX/generated/images/src/image_gray_100x100png.o \
./TouchGFX/generated/images/src/image_green_100x100.o \
./TouchGFX/generated/images/src/image_indBatt.o \
./TouchGFX/generated/images/src/image_indDTC.o \
./TouchGFX/generated/images/src/image_indECT.o \
./TouchGFX/generated/images/src/image_indFuel.o \
./TouchGFX/generated/images/src/image_indHigh.o \
./TouchGFX/generated/images/src/image_indLeft.o \
./TouchGFX/generated/images/src/image_indLow.o \
./TouchGFX/generated/images/src/image_indOil.o \
./TouchGFX/generated/images/src/image_indPark.o \
./TouchGFX/generated/images/src/image_indRight.o \
./TouchGFX/generated/images/src/image_needel.o \
./TouchGFX/generated/images/src/image_race_dash.o \
./TouchGFX/generated/images/src/image_red_100x100.o \
./TouchGFX/generated/images/src/image_speeduino1.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/image_blue_100x100.d \
./TouchGFX/generated/images/src/image_gray_100x100png.d \
./TouchGFX/generated/images/src/image_green_100x100.d \
./TouchGFX/generated/images/src/image_indBatt.d \
./TouchGFX/generated/images/src/image_indDTC.d \
./TouchGFX/generated/images/src/image_indECT.d \
./TouchGFX/generated/images/src/image_indFuel.d \
./TouchGFX/generated/images/src/image_indHigh.d \
./TouchGFX/generated/images/src/image_indLeft.d \
./TouchGFX/generated/images/src/image_indLow.d \
./TouchGFX/generated/images/src/image_indOil.d \
./TouchGFX/generated/images/src/image_indPark.d \
./TouchGFX/generated/images/src/image_indRight.d \
./TouchGFX/generated/images/src/image_needel.d \
./TouchGFX/generated/images/src/image_race_dash.d \
./TouchGFX/generated/images/src/image_red_100x100.d \
./TouchGFX/generated/images/src/image_speeduino1.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/%.o: ../TouchGFX/generated/images/src/%.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src

clean-TouchGFX-2f-generated-2f-images-2f-src:
	-$(RM) ./TouchGFX/generated/images/src/BitmapDatabase.d ./TouchGFX/generated/images/src/BitmapDatabase.o ./TouchGFX/generated/images/src/image_blue_100x100.d ./TouchGFX/generated/images/src/image_blue_100x100.o ./TouchGFX/generated/images/src/image_gray_100x100png.d ./TouchGFX/generated/images/src/image_gray_100x100png.o ./TouchGFX/generated/images/src/image_green_100x100.d ./TouchGFX/generated/images/src/image_green_100x100.o ./TouchGFX/generated/images/src/image_indBatt.d ./TouchGFX/generated/images/src/image_indBatt.o ./TouchGFX/generated/images/src/image_indDTC.d ./TouchGFX/generated/images/src/image_indDTC.o ./TouchGFX/generated/images/src/image_indECT.d ./TouchGFX/generated/images/src/image_indECT.o ./TouchGFX/generated/images/src/image_indFuel.d ./TouchGFX/generated/images/src/image_indFuel.o ./TouchGFX/generated/images/src/image_indHigh.d ./TouchGFX/generated/images/src/image_indHigh.o ./TouchGFX/generated/images/src/image_indLeft.d ./TouchGFX/generated/images/src/image_indLeft.o ./TouchGFX/generated/images/src/image_indLow.d ./TouchGFX/generated/images/src/image_indLow.o ./TouchGFX/generated/images/src/image_indOil.d ./TouchGFX/generated/images/src/image_indOil.o ./TouchGFX/generated/images/src/image_indPark.d ./TouchGFX/generated/images/src/image_indPark.o ./TouchGFX/generated/images/src/image_indRight.d ./TouchGFX/generated/images/src/image_indRight.o ./TouchGFX/generated/images/src/image_needel.d ./TouchGFX/generated/images/src/image_needel.o ./TouchGFX/generated/images/src/image_race_dash.d ./TouchGFX/generated/images/src/image_race_dash.o ./TouchGFX/generated/images/src/image_red_100x100.d ./TouchGFX/generated/images/src/image_red_100x100.o ./TouchGFX/generated/images/src/image_speeduino1.d ./TouchGFX/generated/images/src/image_speeduino1.o

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src


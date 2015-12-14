################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/DataLogger.c \
../Sources/Events.c \
../Sources/main.c 

OBJS += \
./Sources/DataLogger.o \
./Sources/Events.o \
./Sources/main.o 

C_DEPS += \
./Sources/DataLogger.d \
./Sources/Events.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/Peripherals" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/System" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/PDD" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/IO_Map" -I"/home/jtoews/Desktop/keplercpp/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Sources" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Generated_Code" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\Peripherals" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\System" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\PDD" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\IO_Map" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



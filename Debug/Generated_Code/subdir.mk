################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd4.c \
../Generated_Code/CD1.c \
../Generated_Code/CS1.c \
../Generated_Code/Cpu.c \
../Generated_Code/DBCLK.c \
../Generated_Code/EInt1.c \
../Generated_Code/ExtIntLdd1.c \
../Generated_Code/FAT1.c \
../Generated_Code/Inhr1.c \
../Generated_Code/LEDB.c \
../Generated_Code/LEDG.c \
../Generated_Code/LEDPWM.c \
../Generated_Code/LEDR.c \
../Generated_Code/LEDpin1.c \
../Generated_Code/LEDpin2.c \
../Generated_Code/LEDpin4.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/RUNTI.c \
../Generated_Code/SD1.c \
../Generated_Code/SM1.c \
../Generated_Code/SS1.c \
../Generated_Code/TI1.c \
../Generated_Code/TMOUT1.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TU3.c \
../Generated_Code/TU4.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/TimerIntLdd2.c \
../Generated_Code/TimerIntLdd3.c \
../Generated_Code/TmDt1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/WAIT1.c \
../Generated_Code/WAIT2.c \
../Generated_Code/ff.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd4.o \
./Generated_Code/CD1.o \
./Generated_Code/CS1.o \
./Generated_Code/Cpu.o \
./Generated_Code/DBCLK.o \
./Generated_Code/EInt1.o \
./Generated_Code/ExtIntLdd1.o \
./Generated_Code/FAT1.o \
./Generated_Code/Inhr1.o \
./Generated_Code/LEDB.o \
./Generated_Code/LEDG.o \
./Generated_Code/LEDPWM.o \
./Generated_Code/LEDR.o \
./Generated_Code/LEDpin1.o \
./Generated_Code/LEDpin2.o \
./Generated_Code/LEDpin4.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/RUNTI.o \
./Generated_Code/SD1.o \
./Generated_Code/SM1.o \
./Generated_Code/SS1.o \
./Generated_Code/TI1.o \
./Generated_Code/TMOUT1.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TU3.o \
./Generated_Code/TU4.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/TimerIntLdd3.o \
./Generated_Code/TmDt1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/WAIT1.o \
./Generated_Code/WAIT2.o \
./Generated_Code/ff.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd4.d \
./Generated_Code/CD1.d \
./Generated_Code/CS1.d \
./Generated_Code/Cpu.d \
./Generated_Code/DBCLK.d \
./Generated_Code/EInt1.d \
./Generated_Code/ExtIntLdd1.d \
./Generated_Code/FAT1.d \
./Generated_Code/Inhr1.d \
./Generated_Code/LEDB.d \
./Generated_Code/LEDG.d \
./Generated_Code/LEDPWM.d \
./Generated_Code/LEDR.d \
./Generated_Code/LEDpin1.d \
./Generated_Code/LEDpin2.d \
./Generated_Code/LEDpin4.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/RUNTI.d \
./Generated_Code/SD1.d \
./Generated_Code/SM1.d \
./Generated_Code/SS1.d \
./Generated_Code/TI1.d \
./Generated_Code/TMOUT1.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TU3.d \
./Generated_Code/TU4.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/TimerIntLdd2.d \
./Generated_Code/TimerIntLdd3.d \
./Generated_Code/TmDt1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/WAIT1.d \
./Generated_Code/WAIT2.d \
./Generated_Code/ff.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/Peripherals" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/System" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/PDD" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code/IO_Map" -I"/home/jtoews/Desktop/keplercpp/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Sources" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Generated_Code" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\Peripherals" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\System" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\PDD" -I"/home/jtoews/Desktop/keplercpp/workspace_keplercpp/DataLogger/Static_Code\IO_Map" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



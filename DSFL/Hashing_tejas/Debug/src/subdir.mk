################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Hashing_tejas.cpp \
../src/no_replace.cpp \
../src/replace.cpp \
../src/student.cpp 

OBJS += \
./src/Hashing_tejas.o \
./src/no_replace.o \
./src/replace.o \
./src/student.o 

CPP_DEPS += \
./src/Hashing_tejas.d \
./src/no_replace.d \
./src/replace.d \
./src/student.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



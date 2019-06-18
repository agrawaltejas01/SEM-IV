################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Expression_Conversion.cpp \
../src/inpost.cpp \
../src/inpre.cpp \
../src/stack.cpp \
../src/stack_int.cpp 

OBJS += \
./src/Expression_Conversion.o \
./src/inpost.o \
./src/inpre.o \
./src/stack.o \
./src/stack_int.o 

CPP_DEPS += \
./src/Expression_Conversion.d \
./src/inpost.d \
./src/inpre.d \
./src/stack.d \
./src/stack_int.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



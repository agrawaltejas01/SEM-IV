################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Binary\ _Search.cpp \
../src/binary_search.cpp \
../src/sort.cpp 

OBJS += \
./src/Binary\ _Search.o \
./src/binary_search.o \
./src/sort.o 

CPP_DEPS += \
./src/Binary\ _Search.d \
./src/binary_search.d \
./src/sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/Binary\ _Search.o: ../src/Binary\ _Search.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Binary _Search.d" -MT"src/Binary\ _Search.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



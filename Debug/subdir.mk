################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph.cpp \
../Mst.cpp \
../PriorityQueue.cpp \
../ShortestPath.cpp 

OBJS += \
./Graph.o \
./Mst.o \
./PriorityQueue.o \
./ShortestPath.o 

CPP_DEPS += \
./Graph.d \
./Mst.d \
./PriorityQueue.d \
./ShortestPath.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../test/list_test.c 

C_DEPS += \
./test/list_test.d 

OBJS += \
./test/list_test.o 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.c test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"D:\github\list\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-test

clean-test:
	-$(RM) ./test/list_test.d ./test/list_test.o

.PHONY: clean-test


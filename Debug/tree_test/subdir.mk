################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tree_test/tree_test.c 

C_DEPS += \
./tree_test/tree_test.d 

OBJS += \
./tree_test/tree_test.o 


# Each subdirectory must supply rules for building sources it contributes
tree_test/%.o: ../tree_test/%.c tree_test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"E:\eclipse\tree\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-tree_test

clean-tree_test:
	-$(RM) ./tree_test/tree_test.d ./tree_test/tree_test.o

.PHONY: clean-tree_test


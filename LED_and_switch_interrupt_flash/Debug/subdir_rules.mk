################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
gpio.obj: ../gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/Users/mm/Downloads/LED_and_switch_interrupt2/LED_and_switch_interrupt/include" --define=c6748 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="gpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

gpioMux.obj: ../gpioMux.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/Users/mm/Downloads/LED_and_switch_interrupt2/LED_and_switch_interrupt/include" --define=c6748 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="gpioMux.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

interrupt.obj: ../interrupt.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/Users/mm/Downloads/LED_and_switch_interrupt2/LED_and_switch_interrupt/include" --define=c6748 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="interrupt.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

intvecs.obj: ../intvecs.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/Users/mm/Downloads/LED_and_switch_interrupt2/LED_and_switch_interrupt/include" --define=c6748 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="intvecs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/Users/mm/Downloads/LED_and_switch_interrupt2/LED_and_switch_interrupt/include" --define=c6748 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

psc.obj: ../psc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/Users/mm/Downloads/LED_and_switch_interrupt2/LED_and_switch_interrupt/include" --define=c6748 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="psc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



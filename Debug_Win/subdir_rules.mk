################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
F2837xD_CodeStartBranch.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_CpuTimers.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_CpuTimers.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_DefaultISR.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_DefaultISR.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_GlobalVariableDefs.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_Gpio.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_Gpio.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_PieCtrl.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_PieCtrl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_PieVect.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_PieVect.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_SysCtrl.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_SysCtrl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xD_usDelay.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_usDelay.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

Fapi_UserDefinedFunctions.obj: /opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/source/Fapi_UserDefinedFunctions.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O4 --fp_mode=relaxed --include_path="/home/waner/workspace_v11/F28379D_Firmware" --include_path="/opt/ti/ccs1110/ccs/tools/compiler/ti-cgt-c2000_21.6.0.LTS/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/math/CLAmath/c28/include" --include_path="/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/include" --advice:performance=all --define=_LAUNCHXL_F28379D --define=CPU1 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '



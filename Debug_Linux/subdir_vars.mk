################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../2837xD_FLASH_lnk_cpu1.cmd \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/cmd/F2837xD_Headers_nonBIOS_cpu1.cmd 

ASM_SRCS += \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_usDelay.asm 

C_SRCS += \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_CpuTimers.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_DefaultISR.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_Gpio.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_PieCtrl.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_PieVect.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_SysCtrl.c \
/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/source/Fapi_UserDefinedFunctions.c \
../Flash_F28379D.c \
../Peripheral_Setup.c \
../SCIx.c \
../main.c 

C_DEPS += \
./F2837xD_CpuTimers.d \
./F2837xD_DefaultISR.d \
./F2837xD_GlobalVariableDefs.d \
./F2837xD_Gpio.d \
./F2837xD_PieCtrl.d \
./F2837xD_PieVect.d \
./F2837xD_SysCtrl.d \
./Fapi_UserDefinedFunctions.d \
./Flash_F28379D.d \
./Peripheral_Setup.d \
./SCIx.d \
./main.d 

OBJS += \
./F2837xD_CodeStartBranch.obj \
./F2837xD_CpuTimers.obj \
./F2837xD_DefaultISR.obj \
./F2837xD_GlobalVariableDefs.obj \
./F2837xD_Gpio.obj \
./F2837xD_PieCtrl.obj \
./F2837xD_PieVect.obj \
./F2837xD_SysCtrl.obj \
./F2837xD_usDelay.obj \
./Fapi_UserDefinedFunctions.obj \
./Flash_F28379D.obj \
./Peripheral_Setup.obj \
./SCIx.obj \
./main.obj 

ASM_DEPS += \
./F2837xD_CodeStartBranch.d \
./F2837xD_usDelay.d 

OBJS__QUOTED += \
"F2837xD_CodeStartBranch.obj" \
"F2837xD_CpuTimers.obj" \
"F2837xD_DefaultISR.obj" \
"F2837xD_GlobalVariableDefs.obj" \
"F2837xD_Gpio.obj" \
"F2837xD_PieCtrl.obj" \
"F2837xD_PieVect.obj" \
"F2837xD_SysCtrl.obj" \
"F2837xD_usDelay.obj" \
"Fapi_UserDefinedFunctions.obj" \
"Flash_F28379D.obj" \
"Peripheral_Setup.obj" \
"SCIx.obj" \
"main.obj" 

C_DEPS__QUOTED += \
"F2837xD_CpuTimers.d" \
"F2837xD_DefaultISR.d" \
"F2837xD_GlobalVariableDefs.d" \
"F2837xD_Gpio.d" \
"F2837xD_PieCtrl.d" \
"F2837xD_PieVect.d" \
"F2837xD_SysCtrl.d" \
"Fapi_UserDefinedFunctions.d" \
"Flash_F28379D.d" \
"Peripheral_Setup.d" \
"SCIx.d" \
"main.d" 

ASM_DEPS__QUOTED += \
"F2837xD_CodeStartBranch.d" \
"F2837xD_usDelay.d" 

ASM_SRCS__QUOTED += \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_usDelay.asm" 

C_SRCS__QUOTED += \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_CpuTimers.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_DefaultISR.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_Gpio.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_PieCtrl.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_PieVect.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/device_support/f2837xd/common/source/F2837xD_SysCtrl.c" \
"/opt/ti/C2000Ware_4_01_00_00_Linux/libraries/flash_api/f2837xd/source/Fapi_UserDefinedFunctions.c" \
"../Flash_F28379D.c" \
"../Peripheral_Setup.c" \
"../SCIx.c" \
"../main.c" 



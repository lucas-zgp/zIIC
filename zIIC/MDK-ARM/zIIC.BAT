SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files (x86)\nodejs\;C:\Program Files\Git\cmd;C:\Users\lucas\AppData\Local\Microsoft\WindowsApps;C:\Program Files\Bandizip\;C:\Users\lucas\AppData\Roaming\npm;C:\Users\lucas\AppData\Local\Programs\Microsoft VS Code\bin
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F407ZETx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=zIIC
SET CPU_CLOCK=0x0A037A00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via "ziic\startup_stm32f407xx._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\miic.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\tim.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\usart.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_it.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_msp.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_tim.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_tim_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_rcc_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_flash.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_flash_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_flash_ramfunc.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_dma_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_dma.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_pwr.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_pwr_ex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_cortex.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_exti.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\stm32f4xx_hal_uart.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "ziic\system_stm32f4xx.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "zIIC\zIIC.lnp"

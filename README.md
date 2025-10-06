# TM4C123 RTOS Demo with QP/C (QXK + Semaphore + GPIO IRQ)

![Demo Screenshot or Board Photo](docs/board_photo.jpg)

A compact embedded RTOS example on the **EK-TM4C123GXL** (Cortex-M4F) using the **QP/C framework (QXK kernel)**.  
It demonstrates interrupt-based event signaling, thread synchronization via semaphores, and basic LED control.

---

## 📂 Repository Layout

|
├── Application/              # Your application logic (main, bsp)
|
├── CMSIS/Include/             # CMSIS core headers
|
+---qpc             - QP/C framework sources and selected ports
|
├── ek-tm4c123gxl/             # Board/Microcontroller-specific files
|
├── QPC/                        # QP/C framework + QXK port files
|
+---qpc             - QP/C framework sources and selected ports
|
+---ucos2           - uC/OS2 RTOS sources and selected ports
|
......................projects for this lesson.............................
|
+---stm32c031-qxk-keil
|       ...
|       lesson.uvprojx - KEIL project for STM32 NUCLEO-C031C6, QXK kernel
|
+---tm4c123-freertos-keil
|       ...
|       lesson.uvprojx - KEIL project for TM4C123 (TivaC LaunchPad), FreeRTOS
|
+---tm4c123-qxk-gnu
|       ...
|       Makefile       - makefile for TM4C123 (TivaC LaunchPad), QXK kernel, GNU
|
+---tm4c123-qxk-keil
|       ...
|       lesson.uvprojx - KEIL project for TM4C123 (TivaC LaunchPad), QXK kernel
|
\---tm4c123-ucos2-keil
        ...
        lesson.uvprojx - KEIL project for TM4C123 (TivaC LaunchPad), uC/OS2 kernel

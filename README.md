# TM4C123 RTOS Demo with QP/C (QXK + Semaphore + GPIO IRQ)

![Demo Screenshot or Board Photo](docs/board_photo.jpg)

A compact embedded RTOS example on the **EK-TM4C123GXL** (Cortex-M4F) using the **QP/C framework (QXK kernel)**.  
It demonstrates interrupt-based event signaling, thread synchronization via semaphores, and basic LED control.

---

## 📂 Repository Layout

|  
├── Application/                 # Your application logic (main, bsp)  
|  
├── CMSIS/Include/               # CMSIS core headers  
|  
├── ek-tm4c123gxl/               # Board/Microcontroller-specific files  
|  
├── QPC/                         # QP/C framework + QXK port files  
|  
├── targetConfig/                # Target Configurations  

---

## 🛠 Build & Run Instructions

### Prerequisites

- **Code Composer Studio (CCS)** or GCC ARM toolchain  
- **TivaWare SDK** (not included in repo)  
- **QP/C** is included under `QPC/` in this repo  

### Importing in CCS

1. **Import project**:
   - `File → Import CCS Projects` → point to repo root
2. **Include path setup**:
   - Add paths in Project Properties → CCS Build → GNU Compiler → Directories:
     ```
     ${ProjDirPath}/Application
     ${ProjDirPath}/CMSIS/include
     ${ProjDirPath}/ek-tm4c123gxl
     ${ProjDirPath}/QPC/include
     ${ProjDirPath}/QPC/ports/arm-cm/qxk/gnu
     /path/to/TivaWare
     ```
3. **Linker script (if needed)**: select the one under `ek-tm4c123gxl` or your custom `.cmd`  
4. **Build and flash** — connect the LaunchPad, flash via CCS.

## 📄 License & Credits

	•	Licensed under MIT, see LICENSE file
	•	Portions of this project are adapted from Miro Samek’s QP/C lessons; used here for study and extension
	•	This project uses a **reduced version** of the [QP/C Real-Time Embedded Framework](https://www.state-machine.com/products/qp) from Quantum Leaps, licensed under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.html).


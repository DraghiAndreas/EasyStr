<img src="docs/media/EasyStr.gif" width="800" alt="Logo">

# EasyStr Installation Guide

This guide explains how to build and use the **EasyStr** string manipulation library on Windows with either **Visual Studio (MSVC)** or **CLion + MinGW**.  
Both setups have been tested to ensure full functionality.

---

## 📖 Table of Contents
1. [Clone the repository](#1-clone-the-repository)
2. [Build the library](#2-build-the-library)
    - [Option A — Visual Studio (MSVC)](#option-a--visual-studio-msvc)
    - [Option B — CLion + MinGW](#option-b--clion--mingw)
3. [Notes](#3-notes)

---

## 1. Clone the repository

```bash
git clone https://github.com/DraghiAndreas/EasyStr.git
cd EasyStr
```

---

## 2. Build the library

### Option A — Visual Studio (MSVC)

1. Open a **Developer Command Prompt for Visual Studio**.
2. Create a build directory:

```cmd
mkdir build
cd build
```

3. Configure the project:

```cmd
cmake ..
```

4. Build the library and demo:

```cmd
cmake --build . --config Release
```

5. Install the library (**may require admin permissions**):

```cmd
cmake --install . --config Release
```

> ⚠️ **Administrator privileges required:**  
> By default, CMake installs to `C:\Program Files (x86)\EasyStr`, which may require admin rights.
>
> To install without admin rights, specify a custom prefix:
> ```cmd
> cmake --install . --config Release --prefix "C:\Users\YourName\EasyStr"
> ```

**Resulting paths (default):**
- Headers: `C:\Program Files (x86)\EasyStr\include\EasyStr.h`
- Library: `C:\Program Files (x86)\EasyStr\lib\easystr.lib`

**6. To use EasyStr in a Visual Studio project:**
- Add the include path `C:\Program Files (x86)\EasyStr\include` to **C/C++ → Additional Include Directories**.
- Add the library path `C:\Program Files (x86)\EasyStr\lib` to **Linker → General → Additional Library Directories**.
- Add `easystr.lib` to **Linker → Input → Additional Dependencies**.
- Then include it in your code:

```c
#include <EasyStr.h>
```

---

### Option B — CLion + MinGW

> **Note:** MinGW cannot use MSVC `.lib` files. You must build EasyStr with MinGW.

1. Open **MSYS2 MinGW 64-bit terminal**.
2. Update packages and install the MinGW toolchain + CMake:

```bash
pacman -Syu
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake
```

3. Navigate to the EasyStr source folder (for example):

```bash
cd /c/Users/YourName/Desktop/EasyStr
mkdir build-mingw
cd build-mingw
```

4. Generate build files:

```bash
cmake -G "MinGW Makefiles" ..
```

5. Build the library:

```bash
mingw32-make
```

**6. Example `CMakeLists.txt` for using EasyStr in your own CLion project:**

```cmake
cmake_minimum_required(VERSION 3.22)
project(EasyStrDemo C)

set(CMAKE_C_STANDARD 11)

include_directories("C:/Users/YourName/Desktop/EasyStr/include")
link_directories("C:/Users/YourName/Desktop/EasyStr/build-mingw")

add_executable(EasyStrDemo main.c)
target_link_libraries(EasyStrDemo easystr)
```

7. Open the project root in CLion, select your **MinGW toolchain**, reload CMake, build, and run.

8. Include EasyStr in your code:

```c
#include <EasyStr.h>
```

---

## 3. Notes

- EasyStr currently builds as a **static library** (`.lib` / `.a`).
- MinGW and MSVC builds are independent — both can coexist.
- Always use `#include <EasyStr.h>`.
- Use forward slashes `/` in CMake paths for cross-platform compatibility.
- Clean & rebuild projects if CMake paths or toolchains change.

✅ Tested on Windows 10/11 with MSVC 2022 and MinGW (MSYS2)

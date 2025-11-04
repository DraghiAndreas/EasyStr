<img src="docs/media/EasyStr.gif" width="800" alt="Logo">

# EasyStr Installation Guide

This guide explains how to build and use the **EasyStr** string manipulation library on Windows, Linux, and macOS with Visual Studio, CLion + MinGW, or native GCC/Clang.
All setups have been tested to ensure full functionality **on Windows**. Linux and macOS instructions are untested and provided as guidelines only.

---

## 📖 Table of Contents

1. [Clone the repository](#1-clone-the-repository)
2. [Build the library](#2-build-the-library)

   * [Option A — Visual Studio (MSVC)](#option-a--visual-studio-msvc)
   * [Option B — CLion + MinGW](#option-b--clion--mingw)
   * [Option C — Linux (untested)](#option-c--linux-untested)
   * [Option D — macOS (untested)](#option-d--macos-untested)
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
> Default installation path (`C:\Program Files (x86)\EasyStr`) may require admin rights.
> To install without admin rights, specify a custom prefix:
>
> ```cmd
> cmake --install . --config Release --prefix "C:\Users\YourName\EasyStr"
> ```

**Resulting paths (default):**

* Headers: `C:\Program Files (x86)\EasyStr\include\EasyStr.h`
* Library: `C:\Program Files (x86)\EasyStr\lib\easystr.lib`

**6. To use EasyStr in a Visual Studio project:**

* Add the include path `C:\Program Files (x86)\EasyStr\include` to **C/C++ → Additional Include Directories**.
* Add the library path `C:\Program Files (x86)\EasyStr\lib` to **Linker → General → Additional Library Directories**.
* Add `easystr.lib` to **Linker → Input → Additional Dependencies**.
* Then include it in your code:

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

3. Navigate to the EasyStr source folder (example):

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

**6. Example `CMakeLists.txt` for using EasyStr in your CLion project:**

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

### Option C — Linux (untested)

1. Open a terminal.
2. Install dependencies:

* Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential cmake git
```

* Fedora:

```bash
sudo dnf install gcc gcc-c++ make cmake git
```

3. Create a build directory and navigate into it:

```bash
mkdir build
cd build
```

4. Generate build files:

```bash
cmake ..
```

> Optional: Install locally without root:
>
> ```bash
> cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/EasyStr
> ```

5. Build the library and demo:

```bash
make
```

6. Install the library (**may require root if using system paths**):

```bash
sudo make install
```

7. Use EasyStr in your own programs:

```bash
gcc myprogram.c -I/usr/local/include -L/usr/local/lib -leasystr -o myprogram
```

> Adjust paths if using a custom prefix.

8. Include in your code:

```c
#include <EasyStr.h>
```

> ⚠️ **Note:** Linux installation has **not been tested**.

---

### Option D — macOS (untested)

1. Open a terminal.
2. Install dependencies using Homebrew:

```bash
brew install cmake git
```

3. Create a build directory and navigate into it:

```bash
mkdir build
cd build
```

4. Generate build files:

```bash
cmake ..
```

> Optional: Install locally without root:
>
> ```bash
> cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/EasyStr
> ```

5. Build the library and demo:

```bash
make
```

6. Install the library (**may require root if using system paths**):

```bash
sudo make install
```

7. Use EasyStr in your programs:

```bash
clang myprogram.c -I/usr/local/include -L/usr/local/lib -leasystr -o myprogram
```

8. Include in your code:

```c
#include <EasyStr.h>
```

> ⚠️ **Note:** macOS installation has **not been tested**.

---

## 3. Notes

* EasyStr currently builds as a **static library** (`.lib` / `.a`).
* Builds for Windows (MSVC + MinGW), Linux, and macOS are independent.
* Always use `#include <EasyStr.h>`.
* Use forward slashes `/` in CMake paths for cross-platform compatibility.
* Clean & rebuild projects if CMake paths or toolchains change.

✅ Tested on Windows 10/11 (MSVC 2022 + MinGW/MSYS2). Linux and macOS are untested.

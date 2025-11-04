<img src="docs/media/EasyStr.gif" width="800" alt="Logo">

# EasyStr Installation Guide

This guide explains how to install and use the **EasyStr** string manipulation library on Windows with either **Visual Studio** or **CLion + MinGW**.
I have tested both of these methods to assure complete functionality.
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

**Resulting paths (default):**

* Headers: `C:\Program Files (x86)\EasyStr\include\EasyStr.h`
* Library: `C:\Program Files (x86)\EasyStr\lib\easystr.lib`

**6. To use EasyStr in a Visual Studio project:**

* Add the include path `C:\Program Files (x86)\EasyStr\include` to **Additional Include Directories (Project > Properties > C/C++ > Additional Include Directories)**.
* Add the library path `C:\Program Files (x86)\EasyStr\lib` to **Additional Library Directories (Project > Properties > Linker > General > Additional Library Directories)**.
* Add `easystr.lib` to **Additional Dependencies (Project > Properties > Linker > Input > Additional Dependencies)**.
* Include in your code:

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

**6. Use EasyStr in a CLion project by updating your `CMakeLists.txt`:**

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

* MinGW and MSVC builds are independent — you can keep both without conflicts.
* Always use `#include <EasyStr.h>`.
* Use forward slashes `/` in CMake paths for cross-platform compatibility.
* Clean & rebuild projects if CMake paths or toolchains change.

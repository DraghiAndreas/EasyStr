<img src="docs/media/EasyStr.gif" width="800" alt="EasyStr Logo">


<h1 align="center">EasyStr</h1>

<p align="center">
  <em>A lightweight, easy-to-use C library for simplified string manipulation and handling.
</em>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/CMake-3.10%2B-blue?style=flat-square&logo=CMake" />
  <img src="https://img.shields.io/badge/C-C99%2b-lightblue?style=flat-square&logo=c" />
</p>

---

## Table of Contents
- [About](#about)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
   - [Clone the Repository](#1-clone-the-repository)
   - [Building and Installing](#2-building-and-installing-the-library)
- [Usage](#usage)

- [Documentation](#documentation)
- [License](#license)

---

## About

EasyStr is a C library designed to simplify common string operations and provide intuitive string handling capabilities. Whether you're working on a small project or a larger application, EasyStr offers a straightforward API for string manipulation.

---

## Prerequisites

Before installing EasyStr, ensure you have the following tools installed:

- **CMake** (version 3.10 or higher)
- **C Compiler** (GCC, Clang, or MSVC)
- One of the following development environments:
   - MSYS2 MINGW64
   - CLion
   - Visual Studio

---

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/DraghiAndreas/EasyStr.git
cd EasyStr
```

---

### 2. Building and Installing the Library

#### Option A: Using MSYS2

1. Open MSYS2 MINGW64 with administrator privileges
2. Create a build directory and navigate to it:
```bash
mkdir build
cd build
```
> **Note:** While the directory name `build` is not mandatory, it follows standard CMake conventions.

3. Configure the project (this will locate the CMakeLists.txt file in the root directory):
```bash
cmake ..
```

4. Build the library:
```bash
cmake --build .
```

5. Install the library (requires administrator permissions):
```bash
cmake --install .
```

Upon successful installation, you should see output similar to:
```
-- Install configuration: "Release"
-- Installing: C:/Program Files (x86)/EasyStr/lib/libeasystr.a
-- Installing: C:/Program Files (x86)/EasyStr/include/EasyStr.h
-- Installing: C:/Program Files (x86)/EasyStr/lib/pkgconfig/easystr.pc
```

**Important:** Note these installation paths for later configuration:
- `C:/Program Files (x86)/EasyStr/lib`
- `C:/Program Files (x86)/EasyStr/include`

#### Option B: Using CLion or Visual Studio

> **Note:** The choice of IDE for installation does not affect compatibility with other development environments.

##### CLion Instructions

1. Open the EasyStr folder in CLion
2. Right-click on `CMakeLists.txt` and select `Reload CMake Project`
3. CLion will automatically generate a `cmake-build-debug` folder
4. Open the integrated terminal and navigate to the build directory:
```bash
cd cmake-build-debug
```

5. Install the library (requires administrator permissions):
```bash
cmake --install .
```

##### Visual Studio Instructions

1. Open the EasyStr folder in Visual Studio
2. Visual Studio will automatically build the project
3. Locate the build directory
4. Open a command prompt with administrator privileges in the build directory
5. Run the installation command:
```cmd
cmake --install .
```

Upon successful installation, you should see output similar to:
```
-- Install configuration: "Release"
-- Installing: C:/Program Files (x86)/EasyStr/lib/libeasystr.a
-- Installing: C:/Program Files (x86)/EasyStr/include/EasyStr.h
-- Installing: C:/Program Files (x86)/EasyStr/lib/pkgconfig/easystr.pc
```

**Important:** Note these installation paths for later configuration:
- `C:/Program Files (x86)/EasyStr/lib`
- `C:/Program Files (x86)/EasyStr/include`

---

## Usage

### 3. Integrating EasyStr into Your Project

#### Option A: CLion with CMake

1. Create a new CLion project (this will include a `CMakeLists.txt` file)
2. Your initial `CMakeLists.txt` will look similar to this:
```cmake
cmake_minimum_required(VERSION 4.0)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c)
```

3. Add the following configuration lines:
```cmake
include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")
target_link_libraries(untitled1 PRIVATE easystr)
```

Your complete `CMakeLists.txt` should now look like this:
```cmake
cmake_minimum_required(VERSION 4.0)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")

add_executable(untitled1 main.c)

target_link_libraries(untitled1 PRIVATE easystr)
```

4. Right-click on `CMakeLists.txt` and select `Reload CMake Project`
5. You can now use `#include <EasyStr.h>` in your source files

#### Option B: Visual Studio with CMake

1. Create a new Visual Studio CMake project
2. Locate the `CMakeLists.txt` file in your project directory. It will look similar to:
```cmake
cmake_minimum_required(VERSION 3.20)
project(MyTestApp C)

add_executable(MyTestApp MyTestApp.c)
```

3. Add the following configuration lines:
```cmake
include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")
target_link_libraries(MyTestApp PRIVATE easystr)
```

Your complete `CMakeLists.txt` should now look like this:
```cmake
cmake_minimum_required(VERSION 3.20)
project(MyTestApp C)

include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")

add_executable(MyTestApp MyTestApp.c)

target_link_libraries(MyTestApp PRIVATE easystr)
```

4. You can now use `#include <EasyStr.h>` in your source files

#### Option C: Visual Studio without CMake

For traditional Visual Studio projects without CMake:

1. Create a new C project in Visual Studio
2. Right-click on the project in Solution Explorer and select `Properties`
3. Configure the include path:
   - Navigate to **C/C++ → General → Additional Include Directories**
   - Add: `C:\Program Files (x86)\EasyStr\include`
4. Configure the library path:
   - Navigate to **Linker → General → Additional Library Directories**
   - Add: `C:\Program Files (x86)\EasyStr\lib`
5. Link the library:
   - Navigate to **Linker → Input → Additional Dependencies**
   - Add: `easystr.lib`



---

## Documentation

For the complete API reference, detailing all functions, parameters, and return types, please visit:

**[📚 Full Documentation](https://github.com/DraghiAndreas/EasyStr/blob/master/docs/DOCUMENTATION.md)**

---


## License

This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

---

## Contact

**Andreas Draghi** - [@DraghiAndreas](https://github.com/DraghiAndreas)

Project Link: [https://github.com/DraghiAndreas/EasyStr](https://github.com/DraghiAndreas/EasyStr)
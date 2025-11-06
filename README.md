<img src="docs/media/EasyStr.gif" width="800" alt="Logo">

# EasyStr Installation Guide

## 1. Clone the repository

```bash
git clone https://github.com/DraghiAndreas/EasyStr.git
cd EasyStr
```

---

## 2. Building/Installing the library

### Option A - MSYS2
1. Open MSYS2 MINGW64 (run as admin)
2. Run the following commands:
```cmd
mkdir build
cd build
```
Note : the name build is not necessary but it's good practice
3. Run the configuration (This command is going to look for the CMakeLists.txt file from the root folder)
```cmd
cmake ..
```
4. Build the library with:
```cmd
cmake --build .
```
5. And now, finally, the installation **(Admin permissions required)**
```cmd
cmake --install .
```
If everything worked correctly you should see a something like:
```cmd
-- Install configuration: "Release"
-- Installing: C:/Program Files (x86)/EasyStr/lib/libeasystr.a
-- Installing: C:/Program Files (x86)/EasyStr/include/EasyStr.h
-- Installing: C:/Program Files (x86)/EasyStr/lib/pkgconfig/easystr.pc
```
Good job, you got yourself my library, now keep these paths in mind, these will come in handy later:
```cmd
C:/Program Files (x86)/EasyStr/lib
C:/Program Files (x86)/EasyStr/include
```

### Option B — CLion (and VS i guess)
>**Note: Installing the library in CLion or MSYS2 doesn't mean it's going to be any harder to use in VS, than it would be if you installed it in VS**

1. Open the folder EasyStr in CLion.
2. Right click on CMakeLists.txt and press the `Reload CMake Project`
3. 💥BOOM💥 now you have a folder named `cmake-build-debug`
>**Note:** In VS you just have to open EasyStr and it will do the build automatically, but you won't see a build folder, cause microsoft.
> So have fun finding it !

4. Now go ahead, open the built-in terminal and :
```cmd
cd cmake-build-debug
```
or if you're using VS:
```cmd
switch to CLion
nvm
cd *wherever the build folder is*
```
5. And now, finally, the installation **(Admin permissions required)**
```cmd
cmake --install .
```
If everything worked correctly you should see a something like:
```cmd
-- Install configuration: "Release"
-- Installing: C:/Program Files (x86)/EasyStr/lib/libeasystr.a
-- Installing: C:/Program Files (x86)/EasyStr/include/EasyStr.h
-- Installing: C:/Program Files (x86)/EasyStr/lib/pkgconfig/easystr.pc
```
Good job, you got yourself my library, now keep these paths in mind, these will come in handy later:
```cmd
C:/Program Files (x86)/EasyStr/lib
C:/Program Files (x86)/EasyStr/include
```

## 3. Using <EasyStr.h> in a project

### Option A - CLion | Simple

1. Create a new CLion project, you will notice that you have a `CMakeLists.txt` file, good.
2. Open the file, it probably looks something like this:
```cmake
cmake_minimum_required(VERSION 4.0)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c)
```
3. Add the following lines:
```cmake
include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")
target_link_libraries(untitled1 PRIVATE easystr)
```
Now your file should look something like this :
```cmake
cmake_minimum_required(VERSION 4.0)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")

add_executable(untitled1 main.c)

target_link_libraries(untitled1 PRIVATE easystr)
```

7. Now if you try to use  `<EasyStr.h>` in your code, it won't work, duh...
8. You have to `right-click` the `CMakeFile.txt` again, and `Reload CMake Project`.
9. Now `#include <EasyStr.h>` works perfectly fine, check out the documentation for instructions on how to use the functions.

### Option B - VS | Simple

1. Create a new VS project, a `CMake Project`
2. If you look into the folder named after your project you will see there the right `CMakeLists.txt` file.
3. It will probably look something like this:
```cmake
cmake_minimum_required(VERSION 3.20)
project(MyTestApp C)

add_executable(MyTestApp MyTestApp.c)
```
4. Add the following lines:
```cmake
include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")
target_link_libraries(MyTestApp PRIVATE easystr)
```
Now your file should look something like this :
```cmake
cmake_minimum_required(VERSION 3.20)
project(MyTestApp C)

include_directories("C:/Program Files (x86)/EasyStr/include")
link_directories("C:/Program Files (x86)/EasyStr/lib")

add_executable(MyTestApp MyTestApp.c)

target_link_libraries(MyTestApp PRIVATE easystr)
```
5. Now `#include <EasyStr.h>` works perfectly fine, check out the documentation for instructions on how to use the functions.

## Option C - VS | w/o CMake
1. Let me start off saying that idrk why you would want to do this, now that that's out of the way.
2. Create a simple C project.
3. Now, `right-click` on the Project in the `Solution Explorer`, and select `Propreties`
4. Add the include path `C:\Program Files (x86)\EasyStr\include` to **C/C++ → Additional Include Directories.** 
5. Add the library path `C:\Program Files (x86)\EasyStr\lib` to **Linker → General → Additional Library Directories.**
6. Add `easystr.lib` to **Linker → Input → Additional Dependencies.**
---

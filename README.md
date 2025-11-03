<img src="docs/media/EasyStr.gif" width="800" alt="Logo">

## Building

### Using CMake (Recommended)
```bash
# Clone the repository
git clone <your-repo-url>
cd EasyStr

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .

# Run the demo
./demo

# Optional: Install system-wide
sudo cmake --install .
```

### Build Options

- Release build (optimized): `cmake -DCMAKE_BUILD_TYPE=Release ..`
- Debug build (with symbols): `cmake -DCMAKE_BUILD_TYPE=Debug ..`

### Using the Library

After installation:
```c
#include <EasyStr.h>

// Link with: -leasystr
```

Or with pkg-config:
```bash
gcc myprogram.c $(pkg-config --cflags --libs easystr)
```
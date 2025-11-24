# Test directory for Math_Engine

## Technologies and tools:make:

1. Visual Studio Build Tools:
  - Desktop development with C++

  ```bash
  cd path/to/vcpkg
  .\vcpkg integrate install
  ```

1. CMake:
  - Role: Cross-platform build system.
  - Purpose: Generates project build files for your compiler
  - How it fits:
      - Defines project structure
      - Tells compiler how to compile main program and tests
      - Works together with vcpkg to link GoogleTest

  ```powershell
    choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System' -y
    cmake -B build -DCMAKE_TOOLCHAIN_FILE=C:/Users/greyw/VSC_CodeCreations/Math_engine/vcpkg/scripts/buildsystems/vcpkg.cmake
    cmake --build build

  ```

1. GoogleTest(gtest)
  - Role: C++ testing framework.
  - Purpose: Provides a clean way to write and run unit tests.

1. vcpkg
  - Role: C++ package manager
  - Purpose: Manages external libraries like GoogleTest in a cross-platform, reproducible way.

  `bash
  ./vcpkg install gtest
  `
## Building and Running Tests
  ```bash
    # From project root
    cmake -B build -DCMAKE_TOOLCHAIN_FILE=C:/Users/greyw/VSC_CodeCreations/Math_engine/vcpkg/scripts/buildsystems/vcpkg.cmake
    cmake --build build

    # Run tests
    cd build
    ctest -C Debug
  ```


Building a C++ project with CMake involves several steps. Here’s a basic guide to get you started:

1. **Project Structure**:
   Organize your project files in a directory structure. Here is an example structure:

   ```
   MyProject/
   ├── CMakeLists.txt
   ├── src/
   │   └── main.cpp
   ├── include/
   │   └── my_header.h
   └── build/
   ```

2. **Create CMakeLists.txt**:
   Create a `CMakeLists.txt` file in the root of your project directory. This file contains the configuration for building your project. Here is an example for a simple project:

   ```cmake
   cmake_minimum_required(VERSION 3.10)

   # Project name
   project(MyProject)

   # Specify the C++ standard
   set(CMAKE_CXX_STANDARD 14)
   set(CMAKE_CXX_STANDARD_REQUIRED True)

   # Add the include directory
   include_directories(include)

   # Add the executable
   add_executable(MyExecutable src/main.cpp)
   ```

3. **Source Code**:
   Write your C++ source code in the `src` directory and include your header files in the `include` directory. For example:

   `src/main.cpp`:

   ```cpp
   #include "my_header.h"
   #include <iostream>

   int main() {
       std::cout << "Hello, World!" << std::endl;
       return 0;
   }
   ```

   `include/my_header.h`:

   ```cpp
   #pragma once

   // Your header content
   ```

4. **Build the Project**:
   Now, you can build your project using CMake. Open a terminal and navigate to your project directory:

   ```sh
   cd MyProject
   mkdir build
   cd build
   cmake ..
   make
   ```

   - `mkdir build`: Create a build directory.
   - `cd build`: Change to the build directory.
   - `cmake ..`: Run CMake to generate the Makefiles.
   - `make`: Compile the project.

5. **Run the Executable**:
   After building the project, you can run the generated executable:
   ```sh
   ./MyExecutable
   ```

This is a basic setup for a simple C++ project. Depending on your project requirements, you might need to add more configurations to the `CMakeLists.txt` file, such as linking libraries, setting compiler options, or defining custom build commands.

# C++ Functions and ROS Nodes 
 
## Table Of Content
- [C++ Functions and ROS Nodes](#c-functions-and-ros-nodes)
  - [Table Of Content](#table-of-content)
  - [0. Build System Using CMake](#0-build-system-using-cmake)
    - [0.1 What is CMake?](#01-what-is-cmake)
    - [0.2 Setting Up CMake](#02-setting-up-cmake)
    - [0.3 CMakeLists.txt File](#03-cmakeliststxt-file)
    - [0.4 Build and Run](#04-build-and-run)
    - [0.5 Adding New Executable Files](#05-adding-new-executable-files)
    - [Summary:](#summary)
  - [1. Functions](#1-functions)
    - [1.1 Defining a Function](#11-defining-a-function)
    - [1.2 Example: Simple Addition Function](#12-example-simple-addition-function)
    - [1.3 Function Parameters and Arguments](#13-function-parameters-and-arguments)
    - [Example Pass by Value ](#example-pass-by-value-)
    - [Example Pass by Reference ](#example-pass-by-reference-)
    - [1.4 Returning Values from Functions](#14-returning-values-from-functions)
    - [1.5 Function Overloading](#15-function-overloading)
    - [1.6 Example: Function to Calculate Factorial](#16-example-function-to-calculate-factorial)
      - [1.6.1 Function Definition:](#161-function-definition)
      - [5.6.2 Main Function:](#562-main-function)
      - [1.6.3 Recursion Flow:](#163-recursion-flow)
      - [1.6.4 Final Output:](#164-final-output)
      - [Summary:](#summary-1)
    - [Example: Function Overloading to Calculate Area](#example-function-overloading-to-calculate-area)
---

## 0. Build System Using CMake

In this section, we'll go through how to set up and use **CMake** to build your C++ project, which includes compiling and linking all the source files containing your function examples.

### 0.1 What is CMake?

CMake is a cross-platform build system generator. It helps automate the build process for projects, making it easier to compile, link, and manage dependencies across different operating systems and development environments.

### 0.2 Setting Up CMake

To build the project using CMake, you need to create a `CMakeLists.txt` file, which contains the instructions for building the project.

### 0.3 CMakeLists.txt File

Here's a simple `CMakeLists.txt` file that you can use to build the C++ examples mentioned in this project:


```cmake
#define the version of CMake you are using here 3.1
cmake_minimum_required(VERSION 3.1)
#project name
project(first_project)

#C++ version in use, here 17

set(CMAKE_CXX_STANDARD 17)

#add executable main, this creates main.o
add_executable(hello_ros src/ex0.cpp)
```


### 0.4 Build and Run

1. **Create a build directory**:
   CMake recommends building the project in a separate directory (e.g., `build`).
   ```bash
   mkdir build
   cd build
   ```

2. **Generate the build files**:
   Inside the `build` directory, run CMake to generate the build configuration:
   ```bash
   cmake ..
   ```

3. **Build the project**:
   After generating the build files, compile the project using `make`:
   ```bash
   make
   ```

4. **Run the executable**:
   Once the project is built, you can run the executable:
   ```bash
   ./main
   ```

### 0.5 Adding New Executable Files

To add new C++ source files, simply update the `CMakeLists.txt` file by appending them to the `set(SOURCES ...)` list, like so:

```cmake
set(SOURCES
    src/ex1.cpp
    src/ex2.cpp
    src/ex3.cpp
    src/new_example.cpp  # Add new example files here
)

```

### Summary:
- CMake simplifies the process of building C++ projects, especially when managing multiple source files.
- The `CMakeLists.txt` file defines how the project is compiled and linked, and can be easily extended as the project grows.




## 1. Functions

Functions are a way to encapsulate and reuse code. They allow you to break down complex problems into smaller, manageable pieces, which makes your code more organized and easier to understand.

### 1.1 Defining a Function

A function in C++ consists of a return type, a name, a parameter list, and a body. Here's the basic syntax:

```cpp
return_type function_name(parameter_list) {
    // Function body
    return value; // Optional: Only needed if return_type is not void
}
```

### 1.2 Example: [Simple Addition Function](source-code/examples/src/ex1.cpp)

Let's look at a simple example where we define a function that adds two numbers and returns the result:

```cpp
#include <iostream> 

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 5); // Calling the add function
    std::cout << "The sum is: " << result << std::endl; // Output: The sum is: 8
    return 0;
}

```

### 1.3 Function Parameters and Arguments

Functions can take parameters (also known as arguments) that allow you to pass data into the function. These parameters act as placeholders for the actual values you provide when calling the function.

- **Pass by Value**: The value of the argument is copied into the function parameter. Changes to the parameter do not affect the original argument.
### [Example Pass by Value ](source-code/examples/src/ex2.cpp)
  ```cpp
  #include <iostream> 

  void increment(int value) {
      value++;
  }

  int main() {

      int num = 10;
      int total = increment(num);
      std::cout << "num value: " << num << std::endl;
      std::cout << "total value: " << total << std::endl; 
      return 0;
  }
  ```


- **Pass by Reference**: You can pass arguments by reference using the `&` symbol. This allows the function to modify the original argument.
  
### [Example Pass by Reference ](source-code/examples/src/ex3.cpp)
  ```cpp
  #include <iostream> 

  void increment(int &value) {
      value++;
  }

  int main() {

      int num = 10;
      int total = increment(num);
      std::cout << "num value: " << num << std::endl;
      std::cout << "total value: " << total << std::endl; 
      return 0;
  }
  ```

### 1.4 Returning Values from Functions

Functions can return a value to the caller using the `return` statement. The type of the returned value must match the function's return type.

### 1.5 Function Overloading

C++ allows you to define multiple functions with the same name, as long as they have different parameter lists. This is known as function overloading.

```cpp
int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

int main() {
    int result1 = multiply(3, 5); // Calls the int version
    double result2 = multiply(3.5, 5.5); // Calls the double version
    std::cout << "Int multiplication: " << result1 << std::endl; // Output: 15
    std::cout << "Double multiplication: " << result2 << std::endl; // Output: 19.25
    return 0;
}
```

### 1.6 Example: Function to Calculate Factorial
![fraction equation](images/image2.png)

Let's create a function that calculates the factorial of a number using recursion:

```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 5;
    std::cout << "Factorial of " << number << " is: " << factorial(number) << std::endl; // Output: 120
    return 0;
}
```
Let's break The code down step by step:

#### 1.6.1 Function Definition:

```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
```

- **Function Name:** `factorial`
- **Parameter:** `int n` - The function takes a single integer parameter `n`, which is the number for which we want to calculate the factorial.

- **Base Case:**
  ```cpp
  if (n <= 1) {
      return 1;
  }
  ```
  - The base case of the recursion is when `n` is less than or equal to `1`. In this case, the function returns `1`.
  - This is because the factorial of `0` or `1` is `1` by definition.

- **Recursive Case:**
  ```cpp
  return n * factorial(n - 1);
  ```
  - If `n` is greater than `1`, the function calls itself with `n-1` and multiplies the result by `n`.
  - This recursive call continues until it reaches the base case.

#### 5.6.2 Main Function:

```cpp
int main() {
    int number = 5;
    std::cout << "Factorial of " << number << " is: " << factorial(number) << std::endl;
    return 0;
}
```

- **Variable Declaration:**
  ```cpp
  int number = 5;
  ```
  - An integer variable `number` is declared and initialized with the value `5`. This is the number for which the factorial will be calculated.

- **Function Call and Output:**
  ```cpp
  std::cout << "Factorial of " << number << " is: " << factorial(number) << std::endl;
  ```
  - The `factorial` function is called with `number` as the argument.
  - The result of the function call is printed to the console using `std::cout`.
  - The expected output will be `Factorial of 5 is: 120`.

#### 1.6.3 Recursion Flow:
Let's go through the recursion flow when `number = 5`:

- **First Call:** `factorial(5)`  
  Since `5 > 1`, it returns `5 * factorial(4)`.
  
- **Second Call:** `factorial(4)`  
  Since `4 > 1`, it returns `4 * factorial(3)`.

- **Third Call:** `factorial(3)`  
  Since `3 > 1`, it returns `3 * factorial(2)`.

- **Fourth Call:** `factorial(2)`  
  Since `2 > 1`, it returns `2 * factorial(1)`.

- **Fifth Call:** `factorial(1)`  
  Since `1 <= 1`, it returns `1`.

- **Backtracking:**
  - `factorial(2)` returns `2 * 1 = 2`.
  - `factorial(3)` returns `3 * 2 = 6`.
  - `factorial(4)` returns `4 * 6 = 24`.
  - `factorial(5)` returns `5 * 24 = 120`.

#### 1.6.4 Final Output:
- The final output is printed as: `Factorial of 5 is: 120`.

#### Summary:
- **Factorial Calculation:** The function calculates the factorial by multiplying the number by the factorial of the previous number until it reaches `1`.
- **Recursion:** This approach uses recursion to break down the problem into smaller subproblems.
- **Base Case:** The base case ensures the recursion stops when `n` is `1` or less.

### [Example: Function Overloading to Calculate Area](src/ex7.cpp)

---

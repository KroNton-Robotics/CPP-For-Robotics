# C++ Fundamentals for Robotics

![alt text](images/image1.png)
## Table Of Content
- [C++ Fundamentals for Robotics](#c-fundamentals-for-robotics)
  - [Table Of Content](#table-of-content)
  - [1. Introduction to C++](#1-introduction-to-c)
    - [1.1 Key Features of C++](#11-key-features-of-c)
  - [2. Basic Syntax and Structure](#2-basic-syntax-and-structure)
    - [2.1 Comments](#21-comments)
    - [2.3 Installing g++ on Ubuntu](#23-installing-g-on-ubuntu)
    - [2.4 Compile first CPP file: `ex1.cpp`](#24-compile-first-cpp-file-ex1cpp)
    - [Example: Basic Hello World Program ](#example-basic-hello-world-program-)
  - [3. Data Types, Variables, and Constants](#3-data-types-variables-and-constants)
    - [1. Integers](#1-integers)
    - [2. Floating-Point Numbers](#2-floating-point-numbers)
    - [3. Characters](#3-characters)
    - [4. Booleans](#4-booleans)
    - [Data Type Summary:](#data-type-summary)
    - [3.1 Variables](#31-variables)
    - [3.2 Constants](#32-constants)
    - [Example: Adding Two Numbers](#example-adding-two-numbers)
    - [Example: Calculating the Area of a Circle](#example-calculating-the-area-of-a-circle)
  - [4. Control Structures](#4-control-structures)
    - [4.1 Conditionals](#41-conditionals)
    - [4.2 Loops](#42-loops)
    - [Example: Checking if a Number is Even or Odd](#example-checking-if-a-number-is-even-or-odd)
    - [Example: Printing Numbers from 1 to 10](#example-printing-numbers-from-1-to-10)
    - [Example: Sum of Natural Numbers Using a While Loop](#example-sum-of-natural-numbers-using-a-while-loop)
---

## 1. Introduction to C++

C++ is a general-purpose programming language that was developed by Bjarne Stroustrup in the early 1980s. It's an extension of the C language, adding features like object-oriented programming, templates, and exception handling. C++ is known for its performance and flexibility, making it a popular choice for system programming, game development, and applications where efficiency is key.

### 1.1 Key Features of C++

- **Object-Oriented Programming**: C++ supports classes and objects, allowing you to create complex data structures and encapsulate data and behavior.
- **Templates**: With templates, you can create generic functions and classes, enabling code reusability and type safety.
- **Exception Handling**: C++ allows you to handle errors and exceptional situations in a structured way.
- **Standard Template Library (STL)**: This library provides a collection of commonly used data structures and algorithms.

---

## 2. Basic Syntax and Structure

C++ has a syntax that's similar to C, with some additional features. Here's a quick overview of the basic structure of a C++ program:

```cpp
#include <iostream> // Include a standard library for input/output operations

int main() { // Main function, entry point of the program
    std::cout << "Hello, World!" << std::endl; // Output text to the console
    return 0; // Return a status code to the operating system
}
```

In this example, the `#include` directive is used to include a header file, `int main()` defines the entry point of the program, and `std::cout` is used to output text to the console.


### 2.1 Comments

C++ supports two types of comments:

- **Single-line comments**: Start with `//` and continue to the end of the line.
- **Multi-line comments**: Start with `/*` and end with `*/`.


### 2.3 Installing g++ on Ubuntu

To compile C++ code on Ubuntu, you need to have `g++` installed. Here's how to install it:

1. **Update Package List**:
   Open a terminal and update your package list to make sure you have the latest information about available packages:
   ```bash
   sudo apt update
   ```

2. **Install g++**:
   Install `g++` by running the following command:
   ```bash
   sudo apt install g++
   ```

3. **Verify Installation**:
   After installation, you can verify that `g++` is installed correctly by checking its version:
   ```bash
   g++ --version
   ```

   This should display the version of `g++` that is installed, confirming that the installation was successful.

### 2.4 Compile first CPP file: `ex1.cpp`

Here’s the complete example for your `Hello, World!` program:

1. **Create the File**: Save the following code in a file named `ex1.cpp`:

   ```cpp
   #include <iostream> // Include a standard library for input/output operations

   int main() { // Main function, entry point of the program
       std::cout << "Hello, World!" << std::endl; // Output text to the console
       return 0; // Return a status code to the operating system
   }
   ```

2. **Compile and Run**:

   - **Navigate to the Directory**: Open a terminal and navigate to the directory where `ex1.cpp` is saved.

   - **Compile the Code**:
     ```bash
     g++ ex1.cpp -o hello
     ```
     This command compiles the `ex1.cpp` file and creates an executable named `hello`.

   - **Run the Executable**:
     ```bash
     ./hello
     ```
     This command runs the executable, and you should see the output:
     ```
     Hello, World!
     ```

### [Example: Basic Hello World Program ](src/ex1.cpp)


## 3. Data Types, Variables, and Constants

C++ has various data types for different kinds of values. Here's a brief overview:

### 1. Integers
Integers are whole numbers that do not have a fractional component. Different types of integers can be used depending on the range of values you need.

- **`int`**: The most commonly used integer type, typically 32 bits on most systems, representing values from `-2,147,483,648` to `2,147,483,647`.
- **`short`**: A smaller integer type, typically 16 bits, with a range from `-32,768` to `32,767`.
- **`long`**: A larger integer type, typically 32 or 64 bits, with a range that can extend beyond a regular `int`.
- **`long long`**: An even larger integer, usually 64 bits, used when you need to store very large numbers.

**Examples:**
```cpp
int a = 42;           // Standard integer
short b = 32767;      // Maximum value for a short
long c = 1234567890;  // Long integer
long long d = 9223372036854775807LL; // Long long integer
```

### 2. Floating-Point Numbers
Floating-point numbers are used to represent real numbers that can have fractional parts. They are especially useful for representing numbers that require a decimal point.

- **`float`**: A single-precision floating-point number, typically 32 bits, with a precision of about 7 decimal digits.
- **`double`**: A double-precision floating-point number, typically 64 bits, with a precision of about 15 decimal digits.

**Examples:**
```cpp
float e = 3.14;        // Single-precision floating point
double f = 3.14159265;  // Double-precision floating point
```

### 3. Characters
The `char` type is used to store individual characters. Each character is typically stored as a single byte (8 bits).

- **`char`**: Stores a single character or a small integer value (0 to 255 for unsigned, -128 to 127 for signed).

**Examples:**
```cpp
char g = 'A';   // Character 'A'
char h = 65;    // ASCII value for 'A'
```

### 4. Booleans
The `bool` type is used to represent true or false values. In C++ and many other languages, `true` is often represented by `1` and `false` by `0`.

- **`bool`**: Can be `true` or `false`.

**Examples:**
```cpp
bool i = true;   // Boolean true
bool j = false;  // Boolean false
```

### Data Type Summary:
- **`int`, `short`, `long`, `long long`**: Different types of integers, varying in size and range.
- **`float`, `double`**: Floating-point numbers for representing real numbers with fractional parts.
- **`char`**: Stores a single character or small integer value.
- **`bool`**: Represents true or false values.

### 3.1 Variables

Variables in C++ are used to store data. You need to declare a variable before using it, specifying its type and name:

```cpp
int age = 25; // Declares an integer variable named 'age' with a value of 25
```

### 3.2 Constants

Constants are variables whose values cannot be changed after initialization. You can use the `const` keyword or `#define` to define constants:

```cpp
const int MAX_SIZE = 100; // Constant integer with a value of 100
#define PI 3.14159 // Preprocessor constant
```
### [Example: Adding Two Numbers](src/ex2.cpp)

### [Example: Calculating the Area of a Circle](src/ex3.cpp)

---

## 4. Control Structures

Control structures are used to control the flow of a program. Here are some common ones:

### 4.1 Conditionals

C++ supports `if`, `else if`, and `else` statements to execute different code blocks based on conditions:

```cpp
int number = 10;

if (number > 10) {
    std::cout << "Greater than 10" << std::endl;
} else if (number == 10) {
    std::cout << "Equal to 10" << std::endl;
} else {
    std::cout << "Less than 10" << std::endl;
}
```

### 4.2 Loops

Loops allow you to repeat code blocks. C++ has three common loop structures:

- **For Loop**: Ideal for counting or iterating over a range:

```cpp
for (int i = 0; i < 5; i++) {
    std::cout << i << std::endl;
}
```

- **While Loop**: Repeats as long as a condition is true:

```cpp
int count = 0;
while (count < 5) {
    std::cout << count << std::endl;
    count++;
}
```

- **Do-While Loop**: Similar to `while`, but always runs at least once:

```cpp
int count = 0;
do {
    std::cout << count << std::endl;
    count++;
} while (count < 5);
```
- `while` and `do-while` Key Differences:

  - `while loop` : Condition Checked First - May not execute at all if the condition is false from the beginning.

  - `do-while loop` : Condition Checked After - Always executes at least once, regardless of the condition.

### [Example: Checking if a Number is Even or Odd](src/ex4.cpp)
### [Example: Printing Numbers from 1 to 10](src/ex5.cpp)
### [Example: Sum of Natural Numbers Using a While Loop](src/ex6.cpp)
---


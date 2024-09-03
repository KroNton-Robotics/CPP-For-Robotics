# C++ Fundamentals for Robotics

![alt text](images/image1.png)
## Table Of Content
- [C++ Fundamentals for Robotics](#c-fundamentals-for-robotics)
  - [Table Of Content](#table-of-content)
  - [1. Introduction to C++](#1-introduction-to-c)
    - [1.1 Key Features of C++](#11-key-features-of-c)
  - [2. Basic Syntax and Structure](#2-basic-syntax-and-structure)
    - [2.1 Comments](#21-comments)
    - [Example: Basic Hello World Program](#example-basic-hello-world-program)
  - [3. Data Types, Variables, and Constants](#3-data-types-variables-and-constants)
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
  - [5. Functions](#5-functions)
    - [5.1 Defining a Function](#51-defining-a-function)
    - [5.2 Example: Simple Addition Function](#52-example-simple-addition-function)
    - [5.3 Function Parameters and Arguments](#53-function-parameters-and-arguments)
    - [5.4 Returning Values from Functions](#54-returning-values-from-functions)
    - [5.5 Function Overloading](#55-function-overloading)
    - [5.6 Example: Function to Calculate Factorial](#56-example-function-to-calculate-factorial)
    - [Example: Function to Check if a Number is Prime](#example-function-to-check-if-a-number-is-prime)
    - [Example: Function Overloading to Calculate Area](#example-function-overloading-to-calculate-area)
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

 ### [Example: Basic Hello World Program](src/ex1.cpp)
---

## 3. Data Types, Variables, and Constants

C++ has various data types for different kinds of values. Here's a brief overview:

- **Integers**: Whole numbers. Common types include `int`, `short`, `long`, and `long long`.
- **Floating-point numbers**: Numbers with fractional parts. Common types are `float` and `double`.
- **Characters**: Single characters, using `char`.
- **Booleans**: True or false values, using `bool`.

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
### [Example: Checking if a Number is Even or Odd](src/ex4.cpp)
### [Example: Printing Numbers from 1 to 10](src/ex5.cpp)
### [Example: Sum of Natural Numbers Using a While Loop](src/ex6.cpp)
---

## 5. Functions

Functions are a way to encapsulate and reuse code. They allow you to break down complex problems into smaller, manageable pieces, which makes your code more organized and easier to understand.

### 5.1 Defining a Function

A function in C++ consists of a return type, a name, a parameter list, and a body. Here's the basic syntax:

```cpp
return_type function_name(parameter_list) {
    // Function body
    return value; // Optional: Only needed if return_type is not void
}
```

### 5.2 Example: Simple Addition Function

Let's look at a simple example where we define a function that adds two numbers and returns the result:

```cpp
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 5); // Calling the add function
    std::cout << "The sum is: " << result << std::endl; // Output: The sum is: 8
    return 0;
}
```

### 5.3 Function Parameters and Arguments

Functions can take parameters (also known as arguments) that allow you to pass data into the function. These parameters act as placeholders for the actual values you provide when calling the function.

- **Pass by Value**: The value of the argument is copied into the function parameter. Changes to the parameter do not affect the original argument.

- **Pass by Reference**: You can pass arguments by reference using the `&` symbol. This allows the function to modify the original argument.

```cpp
void increment(int &value) {
    value++;
}

int main() {
    int num = 10;
    increment(num);
    std::cout << "Incremented value: " << num << std::endl; // Output: Incremented value: 11
    return 0;
}
```

### 5.4 Returning Values from Functions

Functions can return a value to the caller using the `return` statement. The type of the returned value must match the function's return type.

### 5.5 Function Overloading

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

### 5.6 Example: Function to Calculate Factorial

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

### [Example: Function to Check if a Number is Prime](src/ex7.cpp)

### [Example: Function Overloading to Calculate Area](src/ex8.cpp)

---

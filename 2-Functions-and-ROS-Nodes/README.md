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
  - [2. Writing a ROS C++ Publisher Node that Keeps Counting](#2-writing-a-ros-c-publisher-node-that-keeps-counting)
    - [2.1 Setting Up the ROS Workspace and Package](#21-setting-up-the-ros-workspace-and-package)
      - [Step 1: Create a ROS Workspace](#step-1-create-a-ros-workspace)
      - [Step 2: Create a ROS Package](#step-2-create-a-ros-package)
    - [2.2 Writing the Publisher Node with a Counter](#22-writing-the-publisher-node-with-a-counter)
    - [2.3 Explanation of the Code](#23-explanation-of-the-code)
    - [2.4 Update `CMakeLists.txt`](#24-update-cmakeliststxt)
    - [2.5 Build and Run the Node](#25-build-and-run-the-node)
    - [Summary](#summary-2)
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

To add new C++ Executable files, simply update the `CMakeLists.txt` file by appending them to the `add_executable()` , like so:

```cmake
#add executable main, this creates main.o
add_executable(hello_ros src/ex0.cpp)

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

### [Example: Function Overloading to Calculate Area](source-code/examples/src/ex6.cpp)

---



## 2. Writing a ROS C++ Publisher Node that Keeps Counting

In this section, we will write a ROS publisher node that continuously publishes a count to the `counter` topic. We will first set up the necessary ROS workspace and package, then move on to writing the publisher node.

---

### 2.1 Setting Up the ROS Workspace and Package

#### Step 1: Create a ROS Workspace

1. Open a terminal and create a directory for your ROS workspace:
   ```bash
   mkdir -p ~/ros_ws/src
   ```

2. Navigate to the workspace directory:
   ```bash
   cd ~/ros_ws
   ```

3. Initialize the workspace with `catkin_make`:
   ```bash
   catkin_make
   ```

4. Source your workspace to ensure ROS recognizes it:
   ```bash
   source devel/setup.bash
   ```

#### Step 2: Create a ROS Package

1. Navigate to the `src` folder:
   ```bash
   cd ~/ros_ws/src
   ```

2. Use the `catkin_create_pkg` command to create a package. For this example, let's call the package `my_pub_pkg`, and we will depend on `roscpp` and `std_msgs`:
   ```bash
   catkin_create_pkg my_pub_pkg roscpp std_msgs
   ```

3. Navigate back to the workspace root and build the package:
   ```bash
   cd ~/ros_ws
   catkin_make
   ```

4. Source the workspace again to update the environment:
   ```bash
   source devel/setup.bash
   ```

---

### 2.2 Writing the Publisher Node with a Counter

Now that the workspace and package are ready, we can write the ROS publisher node.

1. Inside the `src` directory of your package, create a `src` folder and a new C++ file for the publisher node:
   ```bash
   mkdir -p ~/ros_ws/src/my_pub_pkg/src
   touch ~/ros_ws/src/my_pub_pkg/src/topic_publisher.cpp
   ```

2. Open `topic_publisher.cpp` in your preferred text editor and add the following code:

```cpp
#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char** argv) {

    // Initialize the ROS node
    ros::init(argc, argv, "topic_publisher");

    // Create a NodeHandle object
    ros::NodeHandle nh;

    // Create a publisher object that will publish to the 'counter' topic
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1000);

    // Set the loop rate to 2 Hz (2 times per second)
    ros::Rate loop_rate(2);

    // Initialize the counter message with an integer value
    std_msgs::Int32 count;
    count.data = 0;

    // Main loop to continuously publish messages
    while (ros::ok())
    {
        // Publish the counter message to the topic
        pub.publish(count);

        // Allow ROS to process callbacks
        ros::spinOnce();

        // Sleep to maintain the loop rate (2 Hz)
        loop_rate.sleep();

        // Increment the counter value
        ++count.data;
    }

    return 0;
}
```

---
### 2.3 Explanation of the Code

1. **Node Initialization**:
   - `ros::init(argc, argv, "topic_publisher")`: Initializes the node with the name `topic_publisher`, making it known to the ROS master.
   
2. **NodeHandle Creation**:
   - `ros::NodeHandle nh`: The NodeHandle is used for node communication with the ROS system (e.g., publishing, subscribing).
   
3. **Creating a Publisher**:
   - `ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1000)`: Advertises that this node will be publishing messages of type `std_msgs::Int32` on the `counter` topic, with a queue size of 1000.
   
4. **Setting the Loop Rate**:
   - `ros::Rate loop_rate(2)`: Sets the rate at which the loop will run to 2 Hz (2 times per second).

5. **Publishing the Counter**:
   - `std_msgs::Int32 count; count.data = 0;`: A message of type `std_msgs::Int32` is initialized with an integer value of 0.
   - `pub.publish(count)`: The message is published to the `counter` topic.

6. **Loop**:
   - `ros::spinOnce()`: Allows ROS to process incoming messages or events (e.g., service callbacks). Although not strictly necessary here, it's good practice to include it in a loop.
   - `loop_rate.sleep()`: Sleeps for the remaining time in the loop to maintain the specified rate (2 Hz).
   - `++count.data;`: Increments the counter with each iteration.


### 2.4 Update `CMakeLists.txt`

After writing the C++ node, ensure your `CMakeLists.txt` file includes the necessary instructions to build the node.

1. Open the `CMakeLists.txt` file located in the `my_pub_pkg` directory:
   ```bash
   nano ~/ros_ws/src/my_pub_pkg/CMakeLists.txt
   ```

2. Add the following lines under the section where executables are defined:

```cmake
# Add the node executable
add_executable(topic_publisher src/topic_publisher.cpp)

# Link the ROS libraries
target_link_libraries(topic_publisher ${catkin_LIBRARIES})

# Add dependencies for message headers
add_dependencies(topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
```

---

### 2.5 Build and Run the Node

1. **Build the workspace**:
   ```bash
   cd ~/ros_ws
   catkin_make
   ```

2. **Run the ROS master**:
   ```bash
   roscore
   ```

3. **Run the publisher node**:
   ```bash
   rosrun my_pub_pkg topic_publisher
   ```

4. **Check the topic**:
   To see the messages being published to the `counter` topic, use:
   ```bash
   rostopic echo /counter
   ```

You should see output similar to:

```bash
data: 0
data: 1
data: 2
data: 3
...
```

---

### Summary

- **Workspace Setup**: You first created a ROS workspace and a package with the necessary dependencies.
- **Publisher Node**: The C++ publisher node continuously publishes an incrementing integer to the `counter` topic.
- **Build System**: Updated `CMakeLists.txt` to compile and link the node.
- **Running the Node**: After building the workspace, you can run the publisher node and monitor its output using `rostopic echo`.




#include <iostream>

int main() {
    int number; // Declare a variable

    std::cout << "Enter an integer: "; // Prompt user for input
    std::cin >> number; // Read the input

    if (number % 2 == 0) { // Check if the number is divisible by 2
        std::cout << "The number is even." << std::endl;
    } else {
        std::cout << "The number is odd." << std::endl;
    }
    return 0;
}

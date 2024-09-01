#include <iostream>

int main() {
    int num1, num2, sum; // Declare variables

    std::cout << "Enter two numbers: "; // Prompt user for input
    std::cin >> num1 >> num2; // Read input from the user

    sum = num1 + num2; // Calculate sum

    std::cout << "The sum is: " << sum << std::endl; // Output the sum
    return 0;
}

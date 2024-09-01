#include <iostream>

int main() {
    int n, sum = 0, i = 1;

    std::cout << "Enter a positive integer: "; // Prompt user for input
    std::cin >> n; // Read the input

    while (i <= n) { // Loop until i is greater than n
        sum += i; // Add i to sum
        i++; // Increment i
    }

    std::cout << "The sum of the first " << n << " natural numbers is: " << sum << std::endl;
    return 0;
}

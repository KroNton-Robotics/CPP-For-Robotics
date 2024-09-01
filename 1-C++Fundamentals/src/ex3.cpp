#include <iostream>
#define PI 3.14159 // Define a constant for Pi

int main() {
    float radius, area; // Declare variables

    std::cout << "Enter the radius of the circle: "; // Prompt user for input
    std::cin >> radius; // Read the radius

    area = PI * radius * radius; // Calculate the area using the formula

    std::cout << "The area of the circle is: " << area << std::endl; // Output the area
    return 0;
}

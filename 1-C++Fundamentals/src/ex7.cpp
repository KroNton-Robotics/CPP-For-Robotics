#include <iostream>
#include <cmath> // For M_PI constant

// Function to calculate the area of a circle
// Takes the radius as a parameter
double calculateArea(double radius) {
    return M_PI * radius * radius; // Area = π * r^2
}

// Function to calculate the area of a rectangle
// Takes the length and width as parameters
double calculateArea(double length, double width) {
    return length * width; // Area = length * width
}

int main() {
    double radius, length, width;

    // Calculate the area of a circle
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle: " << calculateArea(radius) << std::endl;

    // Calculate the area of a rectangle
    std::cout << "Enter the length and width of the rectangle: ";
    std::cin >> length >> width;
    std::cout << "Area of the rectangle: " << calculateArea(length, width) << std::endl;

    return 0;
}

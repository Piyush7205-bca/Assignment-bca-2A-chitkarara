#include <iostream>

int findMaximum(int *a, int *b, int *c) {
    int maxVal = *a; 
    if (*b > maxVal) {
        maxVal = *b; 
    }
    if (*c > maxVal) {
        maxVal = *c; 
    }
    return maxVal;
}

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    int maxNumber = findMaximum(&num1, &num2, &num3);

    std::cout << "Maximum number is: " << maxNumber << std::endl;

    return 0;
}


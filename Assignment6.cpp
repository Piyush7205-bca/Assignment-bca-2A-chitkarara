#include <iostream>
class Sample {
public:
    int findFactorial(int n) {
        int fact = 1;
        for(int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    int findSquare(int n) {
        return n * n;
    }
    int findCube(int n) {
        return n * n * n;
    }
};
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }
    int N;
    try {
        N = std::stoi(argv[1]);
    } catch (std::invalid_argument const &e) {
        std::cerr << "Invalid number: " << argv[1] << std::endl;
        return 1;
    } catch (std::out_of_range const &e) {
        std::cerr << "Number out of range: " << argv[1] << std::endl;
        return 1;
    }
    Sample obj;
    std::cout << "Factorial of " << N << ": " << obj.findFactorial(N) << std::endl;
    std::cout << "Square of " << N << ": " << obj.findSquare(N) << std::endl;
    std::cout << "Cube of " << N << ": " << obj.findCube(N) << std::endl;
    return 0;
}

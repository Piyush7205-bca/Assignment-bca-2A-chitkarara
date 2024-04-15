#include <iostream>
using namespace std;
class Computation {
public:
    // Public member functions
    int compute(int a, int b) {
        return a + b;
    }
    float compute(int a, float b) {
        return a + b;
    }
    double compute(int a, double b) {
        return a + b;
    }
    int compute(char a, char b) {
        return static_cast<int>(a) + static_cast<int>(b);
    }
    int compute(char a, int b) {
        return static_cast<int>(a) + b;
    }
    int compute() {
        return 0; 
    }
private:
    // Private member variables or functions (if any)
};
int main() {
    Computation calculator;
    cout << calculator.compute(5, 3) << endl;          
    cout << calculator.compute(5, 3.5f) << endl;       
    cout << calculator.compute(5, 3.5) << endl;        
    cout << calculator.compute('a', 'b') << endl;      
    cout << calculator.compute('a', 3) << endl;        
    cout << calculator.compute() << endl;              
    return 0;
}

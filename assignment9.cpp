#include <iostream>
using namespace std;
class Number {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}
    friend Number operator+(const Number& num1, const Number& num2);
    friend Number operator-(const Number& num1, const Number& num2);
    void display() {
        cout <<""<< value << endl;
    }
};
Number operator+(const Number& num1, const Number& num2) {
    Number sum;
    sum.value = num1.value + num2.value;
    return sum;
}
Number operator-(const Number& num1, const Number& num2) {
    Number diff;
    diff.value = num1.value - num2.value;
    return diff;
}
int main() {
    Number num1(5);
    Number num2(3);
    Number result_add = num1 + num2;
    Number result_sub = num1 - num2;
    cout << "addition: ";
    result_add.display();
    cout << "subtraction:";
    result_sub.display();
    return 0;
}

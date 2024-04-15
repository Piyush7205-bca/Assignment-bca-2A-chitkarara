#include <iostream>
using namespace std;
int sum_of_series(int n) {
    int total_sum = 0;
    for (int i = 1; i <= n; ++i) {
        total_sum += i * (i + 1) / 2;
    }
    return total_sum;
}
int main() {
    int n;
    cout << "Enter a positive input: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    int result = sum_of_series(n);
    cout << "Output: " << result << endl;
    return 0;
}

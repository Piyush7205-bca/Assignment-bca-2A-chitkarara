#include <iostream>

class ArrayComparer {
private:
    int array1[5]; // Example size, you can adjust as needed
    int array2[5]; // Example size, you can adjust as needed

public:
    void setArray1(int arr[]) {
        for (int i = 0; i < 5; i++) {
            array1[i] = arr[i];
        }
    }

    void setArray2(int arr[]) {
        for (int i = 0; i < 5; i++) {
            array2[i] = arr[i];
        }
    }

    int getSum(int arr[]) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += arr[i];
        }
        return sum;
    }

    void compareArrays() {
        int sum1 = getSum(array1);
        int sum2 = getSum(array2);

        if (sum1 > sum2) {
            std::cout << "Array 1 has a higher sum of elements." << std::endl;
        } else if (sum2 > sum1) {
            std::cout << "Array 2 has a higher sum of elements." << std::endl;
        } else {
            std::cout << "Both arrays have the same sum of elements." << std::endl;
        }
    }
};

int main() {
    ArrayComparer comparer;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};

    comparer.setArray1(arr1);
    comparer.setArray2(arr2);

    comparer.compareArrays();

    return 0;
}

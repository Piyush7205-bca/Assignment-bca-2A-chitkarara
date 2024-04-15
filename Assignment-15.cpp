#include <iostream>

class DynamicArray {
private:
    int *elements; 
    int currentSize; 
    int maxCapacity; 
public:

    DynamicArray(int initialCapacity) : currentSize(0), maxCapacity(initialCapacity) {
        elements = new int[maxCapacity];
    }

    ~DynamicArray() {
        delete[] elements;
    }

    void add(int value) {
        if (currentSize == maxCapacity) {
            int *temp = new int[2 * maxCapacity];
            for (int i = 0; i < currentSize; ++i) {
                temp[i] = elements[i];
            }
            delete[] elements;
            elements = temp;
            maxCapacity *= 2;
        }
        elements[currentSize++] = value;
    }

    int getSize() const {
        return currentSize;
    }

    int get(int index) const {
        if (index < 0 || index >= currentSize) {
            std::cerr << "Index out of bounds" << std::endl;
            return -1; 
        }
        return elements[index];
    }
};

int main() {
    DynamicArray myDynamicArray(5);

    for (int i = 0; i < 10; ++i) {
        myDynamicArray.add(i);
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < myDynamicArray.getSize(); ++i) {
        std::cout << myDynamicArray.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}


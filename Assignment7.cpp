#include<iostream>
#include<cstring>
using namespace std;
class sample {
public:
    char *name;
    sample() {
nullptr;
    }
    sample(const char *str) {
        int length = strlen(str);
        name = new char[length + 1];
        strcpy(name, str);
    }
    sample(const sample& other) {
        if (other.name != nullptr) {
            int length = strlen(other.name);
            name = new char[length + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }
    ~sample() {
        delete[] name;
    }
};
int main(int argc, char *argv[]) {
    sample user1("chitkara");
    sample user2 = user1;
    delete[] user2.name;
    user2.name = new char[strlen("dummy") + 1];
    strcpy(user2.name, "dummy");
    cout << "User1's name: " << user1.name << endl;
    cout << "User2's name: " << user2.name << endl;
    return 0;
}
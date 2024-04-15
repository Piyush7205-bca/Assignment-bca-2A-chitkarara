#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision
class User {
private:
    std::string name;
    int birthYear;
    int birthMonth;
    int birthDay;
    double salary;
public:
    User(const std::string& name, int birthYear, int birthMonth, int birthDay, double salary) :
        name(name), birthYear(birthYear), birthMonth(birthMonth), birthDay(birthDay), salary(salary) {}

    bool operator==(const User& other) const {
        return (birthYear == other.birthYear) && (birthMonth == other.birthMonth) && (birthDay == other.birthDay);
    }

    double operator+(const User& other) const {
        return (salary + other.salary) / 2.0;
    }

    double operator+(double increment) const {
        if (increment == 0) return salary;
        return salary + (salary * increment / 100);
    }

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "Name: " << user.name << ", Birth Year: " << user.birthYear << ", Salary: "
           << std::fixed << std::setprecision(2) << user.salary;
        return os;
    }
};

int main() {
    User a("John", 1990, 5, 15, 50000);
    User b("Alice", 1985, 8, 25, 60000);

    bool c = (a == b);
    double d = a + b;

    std::cout << "Result of comparison: " << std::boolalpha << c << std::endl;
    std::cout << "Average salary: " << std::fixed << std::setprecision(2) << d << std::endl;

    double e = a + 5;
    double f = b + 10;

    std::cout << "New salary of user1 after 5% increment: " << std::fixed << std::setprecision(2) << e << std::endl;
    std::cout << "New salary of user2 after 10% increment: " << std::fixed << std::setprecision(2) << f << std::endl;

    return 0;
}
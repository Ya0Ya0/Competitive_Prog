#include <iostream>
#include <string>

class Department {
public:
    Department(const std::string& name) : deptName(name) {}

    std::string getName() const { return deptName; }
    void setName(const std::string& name) { deptName = name; }

private:
    std::string deptName;
};

class Employee {
public:
    Employee(const std::string& name, Department* dept)
        : empName(name), department(dept) {}

    std::string getName() const { return empName; }
    std::string getDepartmentName() const { return department->getName(); }

private:
    std::string empName;
    Department* department; // Pointer to Department
};

int main() {
    Department salesDept("Sales");
    Employee john("John Doe", &salesDept);

    std::cout << john.getName() << " works in the " << john.getDepartmentName() << " department." << std::endl;

    return 0;
}//	Starters 135 (Rated till 5-Stars)
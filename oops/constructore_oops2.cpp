#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    // non-parametirized constructors
    string name;
    string dept;
    double salary;
    Employee()
    {
        salary = 25000;
    }

    Employee(string name, string dep)
    {
        name = name;
        dept = dep;
    }
};
int main()
{

    Employee();
    Employee emp;
    cout << emp.salary << endl;

    return 0;
}
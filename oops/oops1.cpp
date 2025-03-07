#include<iostream>
#include<string>
using namespace std;

class Teacher{
    // properties/attributes
// private: // means all the methods and attributes are private
private:
    double salary; // now the slary becomes private, so we cannot access the salary variable inside main function
public:
    string name;
    string dept;
    string subject;

    //methods / member functions
    void changeDept(string newDept){
        dept = newDept;
    }
    // setter , using the setter and getter fucntion  we can access the salary varibale inside the main, because the setSalary ad getSalary both are public methods
    void setSalary(double s){
        salary = s;
    }
    //getter
    double getSalary(){
        return salary;
    }

};
int main(){

    // creating object
    Teacher t1;
    t1.changeDept("bengali");
    // now we can use the salary arrtibute
    t1.setSalary(25000);
    cout << t1.getSalary();

    return 0;
}
#include <iostream>
using namespace std;

class Employee
{
protected:
  int id{};
  string name{};
  double basic{};
public:
  Employee(){
    cout << "Enter Employe name: ";
    getline(cin >> std::ws, name);
    cout << "Enter Employee id and basic salary: ";
    cin >> id >>  basic;
  }

};

class Salary : public Employee{
private:
  double hra{}, da{}, bonus{};
public:
  Salary(){
    hra = basic * .2;
    da = basic * .1;
    bonus = basic * .05;
  }
  double getGross(){
    return basic + hra + da + bonus;
  }
  
  double getTax(){
    return getGross()* .03;
  }
  double getNet(){
    return getGross() - getTax();
  }
  void salarySlip(){
    cout << "Name: " << name << " ID: " << id << '\n';
    cout << "Basic Salary: Rs." << basic << "\nGross Salary: Rs." << getGross();
    cout << "\nTax: Rs." << getTax() << "\nNetSalary: Rs." << getNet(); 
  }
};

int main(){
  Salary s1;
  s1.salarySlip();
  cout << "\nBy Aryan Baral\n";
}

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Employee {
public:
  int empId;
  char
      name[50]; // Fixed-size char array required for raw binary byte operations
  float salary;

  // Get input from user
  void getEmployee() {
    cout << "Enter Employee ID: ";
    cin >> empId;
    cout << "Enter Name: ";
    cin >> ws; // Clear leading whitespace/newlines from input buffer
    cin.getline(name, 50);
    cout << "Enter Salary: ";
    cin >> salary;
  }

  // Display formatted object data
  void displayEmployee() const {
    cout << left << setw(12) << empId << setw(25) << name << fixed
         << setprecision(2) << setw(12) << salary << "\n";
  }
};

int main() {
  int count;
  cout << "How many employee records would you like to add? ";
  cin >> count;

  // 1. Open binary file in append mode to preserve existing records
  ofstream outFile("employee.dat", ios::binary | ios::app);
  if (!outFile) {
    cerr << "Error opening 'employee.dat' for writing!\n";
    return 1;
  }

  Employee emp;
  for (int i = 0; i < count; ++i) {
    cout << "\n--- Enter details for Employee " << (i + 1) << " ---\n";
    emp.getEmployee();
    // Write raw bytes of Employee object to file
    outFile.write((char *)&emp, sizeof(emp));
  }
  outFile.close();
  cout << "\n[Success] Record(s) appended to 'employee.dat'.\n";

  // 2. Open binary file for reading
  ifstream inFile("employee.dat", ios::binary);
  if (!inFile) {
    cerr << "Error opening 'employee.dat' for reading!\n";
    return 1;
  }

  cout << "\n EMPLOYEE RECORDS \n";
  cout << left << setw(12) << "Emp ID" << setw(25) << "Name" << setw(12)
       << "Salary" << "\n";
  cout << string(49, '-') << "\n";

  // Read one Employee object at a time; loop automatically stops at EOF
  while (inFile.read((char *)&emp, sizeof(emp))) {
    emp.displayEmployee();
  }

  inFile.close();
  return 0;
}

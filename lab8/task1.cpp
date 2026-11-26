#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  string name{};
  int roll{};
  float marks{};

  void getData() {
    cout << "Enter Name, Roll Number, and marks: ";
    cin >> name >> roll >> marks;
  }

  void putData() const {
    cout << left << setw(20) << name << setw(15) << roll << fixed
         << setprecision(2) << setw(10) << marks << "\n";
  }
};

int main() {
  Student students[5];
  char str[99];

  // 1. Open file using ofstream for writing
  ofstream outFile("students.txt");
  if (!outFile) {
    cerr << "Error opening file for writing!\n";
    return 1;
  }

  cout << "__ Enter Student Data __\n";
  for (int i = 0; i < 5; i++) {
    students[i].getData();
    // Write record formatted with spaces and a newline at the end
    outFile << students[i].name << " " << students[i].roll << " "
            << students[i].marks << "\n";
  }
  outFile.close();

  // 2. Open file using ifstream for reading
  ifstream inFile("students.txt");
  if (!inFile) {
    cerr << "Error opening file for reading!\n";
    return 1;
  }

  cout << "\n__ Displaying File Contents __\n";
  cout << left << setw(20) << "Name" << setw(15) << "Roll" << setw(10)
       << "Marks" << "\n";
  cout << string(45, '-') << "\n";

  Student temp;
  // Condition checks success of reading all 3 fields
  while (!inFile.eof()) {
    inFile >> temp.name >> temp.roll >> temp.marks;
    if (inFile) {
      temp.putData();
    }
  }
  inFile.close();

  return 0;
}

#include <fstream>
#include <iostream>
using namespace std;

class Student {

public:
  string name;
  int roll;
  double marks;

  void get_data() {
    cout << "Student data:" << " :";
    cin >> name >> roll >> marks;
  }
};

int main() {
  Student students[5];
  string buffer;
  ofstream outFile("students.txt");
  if (!outFile) {
    return 1;
  }
  cout << "Enter student details: ";
  for (int i = 0; i < 2; i++) {
    cout << "Student " << i + 1 << " :";
    cin >> students[i].name >> students[i].roll >> students[i].marks;
    outFile << students[i].name << " " << students[i].roll << " "
            << students[i].marks << "\n";
  }
  outFile.close();

  ifstream inFile("students.txt");

  Student temp;
  while (!inFile.eof()) {
    inFile >> temp.name >> temp.roll >> temp.marks;
  }
}

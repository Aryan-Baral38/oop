#include <iostream>
using namespace std;

class Student
{
protected:
  int id{}, sem{};
  string name{};
public:
  Student(int id, int sem, string name){
    this->id = id;
    this->sem = sem;
    this->name = name;

  }
  void displayStudentInfo(){
    cout << "Name: " << name << " ID: " << id << " Semester: " << sem << '\n';
    
  }
};

class Marks : public Student
{
protected:
  double  obtained_marks[5]{};
public:
  Marks(int id, int sem, string name, double marks[]) : Student(id , sem, name){
    for (int i = 0; i < 5; i++){
      obtained_marks[i] = marks[i];
    }
  }
  void displayMarks(){
    cout << "Marks obtained:\n";
    for (int i = 0; i < 5; i++){
      cout << "Subject: " << i+1 << ":: Marks: "  << obtained_marks[i] << '\n';

    }
  }

};

class Result : public Marks
{
private:
  double total, percentage;
  string division;
  bool failed;
public:
  Result(int id, int sem, string name, double marks[]) : Marks(id, sem, name, marks){
    total = 0, percentage = 0;
  }
  
  void calculateResult(){
    for (int i = 0; i < 5; i++){
      total += obtained_marks[i];
      if (obtained_marks[i] < 32){
        failed = true;
      
      }
    }
    percentage = total / 5;
        
    if (percentage >= 80){
      division = "Distinction";
    }
    if (percentage < 80){
      division = "First";
    }
    if (percentage < 60){
      division = "Second";
    }
    
    if (percentage < 45){
      division = "Third";
    }
    if (percentage == 32){
      division = "Pass";
    }
    if (percentage < 32 || failed){
      division = "failed";
    }
    return;

  }
   void displayResult(){

    displayStudentInfo();
    displayMarks();
    calculateResult();
    cout << "Total: " << total << endl;
    cout << "percentage: "<< percentage << endl;
    cout << "division: " << division;
    
    
  }
};

int main()
{
  double marks[] = {44, 75, 83, 90, 79};
  Result s1(100, 2, "Aryan Baral", marks);
  s1.displayResult();
  return 0;
}

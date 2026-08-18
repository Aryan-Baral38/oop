#include <iostream>
using namespace std;



int main(){
  int  marks[5];
  cout << "Enter marks in 5 subjects: ";
  for (int i = 0; i < 5; i++){
    cin >> marks[i];
  }
  try{
    for (int i = 0; i < 5; i++){
      if (marks[i] < 0 || marks[i] > 100){throw marks[i];}
    }
  }
  catch (int i){
    if (i < 0){
      cout << "Marks Less than 0: " << i;
      return 1;
    }
    else if (i > 100){
      cout << "Marks greater than 100: " << i;
      return 1;
    }
  }
  cout << "marks: ";
  for (int i = 0; i < 5; i++){
    cout << marks[i] << ' ';
  }
  cout << "\n";

  return 0;
}

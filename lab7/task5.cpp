#include <iostream>
using namespace std;

class Calculator
{
public:
    void divide(int a, int b){
    try{
      if (b == 0) {throw 0;}
      else if (a < 0 || b < 0){
        std::string n = "Negative";
        throw n; 
      }
      cout << a << "/" << b << "= " << (float) a/b; 
    }
    catch(int){throw;}
    catch(std::string){throw;}
  }
};

int main(void){
  Calculator c;
  int x, y;
  cout << "Enter two numbers to divide: ";
  cin >> x >> y;
  try{
    c.divide(x, y);
  }
  catch(int i){
    if (i == 0){cout << "Error: divide by zero";}
  }
  catch (std::string s){
    if (s == "Negative"){cout << "Error: Negative Numbers";}
  }
  return 0;
}

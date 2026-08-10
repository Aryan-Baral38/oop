//tasks 4
#include <iostream>
using namespace std;

class Rupees {
private:
  float amt;

public:
  Rupees(float r = 0) { amt = r; }
  void displayRupees() { cout << "Rupees Amount: " << amt << endl; }
};

class Dollars {
private:
  float amt;

public:
  Dollars(float d) { amt = d; }
  operator Rupees() {
    Rupees temp(amt * 135);
    return temp;
  }
  void displayDollars() { cout << "Dollar Amount: " << amt << endl; }
};

int main() {
  Dollars d1(23.5);
  Rupees r1 = (Rupees)d1;
  d1.displayDollars();
  r1.displayRupees();
  cout << "By Aryan Baral\n";
  return 0;
}

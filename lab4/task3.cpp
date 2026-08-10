#include <iomanip>
#include <iostream>
#define km_to_miles 0.62137
using namespace std;

class Kilometer {
private:
  float km;

public:
  Kilometer(float k = 0) { km = k; }

  float getKilometers() { return km; }

  void displayKilometers() { cout << "Km: " << km << endl; }
};

class Mile {

private:
  float miles;

public:
  Mile(float m = 0) { miles = m; }

  Mile(Kilometer k) { miles = km_to_miles * k.getKilometers(); }

  void displayMiles() { cout << setprecision(2) << "Miles: " << miles << endl; }
};
int main() {
  Kilometer k1(12.3);
  Mile m2(k1);
  k1.displayKilometers();
  cout << "In miles: ";
  m2.displayMiles();
  cout << "By Aryan baral\n";
  return 0;
}

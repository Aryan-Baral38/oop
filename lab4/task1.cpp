#include <iostream>

using namespace std;

class Distance {
private:
  int feet{}, inch{};

public:
  Distance(float f) {
    feet = (int)f;
    inch = (f - feet) * 12;
  }
  void displayDistance() { cout << feet << "'" << inch << "\" "; }
};

int main() {
  Distance d1(12.5);
  d1.displayDistance();
  cout << "\nBy Aryan Baral\n";

  return 0;
}

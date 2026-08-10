#include <iostream>

using namespace std;

class Distance {
private:
  int feet{}, inch{};

public:
  Distance(int i, int f) {
    feet = f;
    inch = i;
  }
  operator float() { return feet + inch / 12.0; }

  void displayDistance() { cout << feet << '"' << inch << "\"\n"; }
};

int main() {
  Distance d2(3, 7);
  cout << "distance in feet and inch: ";
  d2.displayDistance();
  float dist = d2;
  cout << "Distance in decimal: " << dist << " feet";
  cout << "\nBy Aryan Baral\n";
  return 0;
}

#include <iomanip>
#include <iostream>
typedef enum { a, b, c, d, e } alp;

using namespace std;
int main() {
  int *p = new int[5];
  for (int i = 0; i < 5; i++) {
    *(p + i) = i;
    cout << *(p + i) << " ";
  }
  cout << endl << setw(30) << setfill('_');
  for (int i = 0; i < 5; i++) {
    *(p + i) = i + 1;
    cout << *(p + i) << " ";
  }
  delete[] p;

  alp this_alph = a;
  switch (this_alph) {
  case 0:
    cout << "Its a";
    break;
  default:
    cout << "Not a";
  }
}

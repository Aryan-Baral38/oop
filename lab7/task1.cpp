//template
#include <iostream>
using namespace std;

template <class T>

T larger(T x, T y){
  return (x > y)?x:y;
}

int main(){
  cout << "Larger of 3 and 5: " << larger<int>(3, 5) << '\n';
  cout << "Larger of 7.4 and 6.5: " << larger<double>(7.4,6.5) << '\n';
  cout << "Larger of 'c' and 'z': " << larger<char>('c', 'z') << '\n';
  return 0;
}

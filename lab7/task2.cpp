#include <iostream>
using namespace std;

template <class T>
class Group 
{
private:
  T a, b;
public:
  Group(T a, T b){
    this->a = a;
    this->b = b;
  }
  void disp_sum_and_difference(){
    cout << a << " + " << b << "= " << a + b << '\n';
    cout << a << " - " << b << "= " << a - b << '\n';
  }
  

};

int main(){
  Group<int>  g1(12, 31);
  Group<float> g2(31.3, 21.8);
  g1.disp_sum_and_difference();
  g2.disp_sum_and_difference();
  return 0;
}

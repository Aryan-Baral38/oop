#include <iostream>
#define PI 3.1415
using namespace std;


class Shape
{
public:
  virtual float get_area(){
    return 0;
  }
  void display_area(){
    cout << "Area: " << get_area() << '\n';
  }
};

class Circle : public Shape
{
private:
  float radius;

public:
  Circle(float r){
    radius = r;
  }
  float get_area(){
    return PI * radius * radius;
  }
};

class Rectangle: public Shape
{
private:
  float l,b;
public:
  Rectangle(float len, float bre){
    l = len, b = bre;
  }
  float get_area(){
    return l * b;
  }
};

int main(){

  Shape *s;
  Circle c1(12);
  cout << "Using Vritual functions\n";
  cout << "Area of Circle: ";
  c1.display_area();
  Rectangle r1(12, 3.5);
  cout << "Area of Rectangle: ";
  r1.display_area();
  cout << "Using late binding \n";
  s = &c1;
  cout << "Area of Circle: ";
  s->display_area();
  s = &r1;
  cout << "Area of Rectangle";
  s->display_area();
  return 0;
}

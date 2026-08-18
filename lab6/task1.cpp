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

  Circle circleObj(12);
  Rectangle rectObj(12, 3.5);
  Shape *ptr1 = &circleObj;
  cout << "Area of Circle: ";
  ptr1->display_area();
  Shape *ptr2 = &rectObj;
  cout << "Area of Rectangle";
  ptr2->display_area();
  return 0;
}

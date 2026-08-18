#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void makesound() = 0;
};

class Dog: public Animal
{
public:
  void makesound(){
    cout << "Woof Woof\n";
  }
};
class Cat: public Animal
{
public:
  void makesound(){
    cout << "Meow Meow\n";
  }
};
int main(){
  Animal *ptr1 = new Dog();
  Animal *ptr2 = new Cat();
  cout << "Dog says: ";
  ptr1->makesound();
  cout << "Car says: ";
  ptr2->makesound();

  return 0;  
}

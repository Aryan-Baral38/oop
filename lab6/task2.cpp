#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void makesound() = 0;
  virtual ~Animal(){};
};

class Dog: public Animal
{
public:
  void makesound() override {
    cout << "Woof Woof\n";
  }
  ~Dog(){
    cout << "The dog ran away\n";
  }
};

class Cat: public Animal
{
public:
  void makesound() override {
    cout << "Meow Meow\n";
  }
  ~Cat(){
    cout << "The cat ran away\n";
  }
};

int main(){
  Animal *ptr1 = new Dog();
  Animal *ptr2 = new Cat();

  cout << "Dog says: ";
  ptr1->makesound();
  delete ptr1;
  cout << "Cat says: "; 
  ptr2->makesound();
  delete ptr2;

  return 0;  
}

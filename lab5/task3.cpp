#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
  int id;
  string name;
  double unit_price;
public:
  Product(int id, string name, double unit_price){
    this->id = id;
    this->unit_price = unit_price;
    this->name = name;
  }
  
  void displayProductInfo(){
    cout << "Product name: " << name << " Id: " << id << " Price: " << unit_price;
  }

};

class Order: public Product
{
protected:
  int quantity{};
  double total{};
public:
  Order(int id, string name, double unit_price, int quantity) : Product(id, name, unit_price){
    this->quantity = quantity;
    calculateTotal();
  }
  void calculateTotal(){
    total = quantity * unit_price;
  }

  
};

class Discount: public Order
{
protected: 
  double discount{}, finalCost{};
public:
  Discount(int id,  string name, double unit_price, int quantity) : Order(id, name, unit_price, quantity){
    discount = discountAmt(total);
    finalCost = total - discount;
  }
  double discountAmt(double amt){

    if (amt >= 50000 ){
      return amt * .15;
    }
    if (amt >= 20000){
      return amt * .10;
    }
    return amt;
  }
  
  void displayFinalPrice(){
    displayProductInfo();
    cout << "\nPre-discount amount: " << total;
    cout << "\nDiscount amt: " << discount << "\n";
    cout << "Final Amount: " << finalCost << "\n";
  }
};



int main(){
  Discount d(102, "soap", 20, 8000); 
  d.displayFinalPrice();
  return 0;
}

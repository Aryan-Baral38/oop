#include <iostream>
using namespace std;

template <class T> class Item {
protected:
  int code;
  T price;

public:
  Item(T x, int y) {
    price = x;
    code = y;
  }
  void info() {
    cout << "Product code: " << code << "\nPrice: " << price << '\n';
  }
};

class DiscountedItem : public Item<double> {
private:
  double discountPercent;

public:
  DiscountedItem(double x, double percent, int code) : Item(x, code) {
    discountPercent = percent;
  }
  double finalPrice() { return price - price * discountPercent / 100; }
  void disp_price() { cout << "Discounted price: " << finalPrice() << '\n'; }
};
int main() {
  DiscountedItem a(1200, 21.5, 22);
  a.info();
  a.disp_price();
  return 0;
}

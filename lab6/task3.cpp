#include <iostream>
using namespace std;

class Account
{
private:
  float balance{};
  static int totalAccounts;
public:
  Account(float bal){
    balance = bal;
    totalAccounts++;
  }
  static int getCount(){
    return totalAccounts;
  }
  void displayBalance(){
    cout << "Balance: " << balance << endl;
  }
  friend void addInterest(Account&, Account&,float);
};
void addInterest(Account &a1, Account &a2, float rate){
  a1.balance += a1.balance * rate/100.0;
  a2.balance += a2.balance * rate/100.0;
}
int Account::totalAccounts = 0;

int main(){
  
  float rate = 20.2f;
  Account a(120000), b(210000);
  cout << "Total Accounts: " << Account::getCount()<< endl;
  cout << "Before Interest:\n";
  cout << "Account A: ";
  a.displayBalance();
  cout << "Account B: ";
  b.displayBalance();
  cout << "Total with interest:\n";
  addInterest(a,b, rate);
  cout << "Account A: ";
  a.displayBalance();
  cout << "Account B:";
  b.displayBalance();
  return 0;
}

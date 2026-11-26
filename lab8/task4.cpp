#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Book {
private:
  string title;
  string author;
  double price;

public:
  // Default Constructor
  Book() : title(""), author(""), price(0.0) {}

  // Parameterized Constructor
  Book(string t, string a, double p) : title(t), author(a), price(p) {}

  // Overloaded Insertion Operator (<<)
  // Writes title, author, and price to the output stream, returning the stream
  // reference for chaining.
  friend ostream &operator<<(ostream &out, const Book &b) {
    out << b.title << " " << b.author << " " << b.price;
    return out;
  }

  // Overloaded Extraction Operator (>>)
  // Reads title, author, and price from the input stream, returning the stream
  // reference.
  friend istream &operator>>(istream &in, Book &b) {
    in >> b.title >> b.author >> b.price;
    return in;
  }

  // Member function to display book details neatly to the console
  void display() const {
    cout << "Title: " << title << " | Author: " << author << " | Price: $Rs."
         << price << endl;
  }
};

int main() {
  // 1. Open file in output mode to write book objects
  ofstream outFile("books.txt");
  if (!outFile) {
    cerr << "Error opening 'books.txt' for writing!" << endl;
    return 1;
  }

  // Creating sample Book objects (using underscores for multi-word strings to
  // ensure clean token reading)
  Book b1("C++_How_to_Program", "Deitel", 1500);
  Book b2("Object_Oriented_Programming_in_C++", "Robert", 2000);
  Book b3("C++_The_Complete_Reference", "Hilbert", 1700);

  // Writing books to the file using the overloaded insertion operator
  outFile << b1 << endl;
  outFile << b2 << endl;
  outFile << b3 << endl;

  outFile.close();

  // 2. Open file in input mode to read book objects back
  ifstream inFile("books.txt");
  if (!inFile) {
    cerr << "Error opening 'books.txt' for reading!" << endl;
    return 1;
  }

  cout << "--- Reading and Displaying Books from 'books.txt' ---" << endl;
  Book tempBook;

  // Read using the overloaded extraction operator inside a while loop until EOF
  while (inFile >> tempBook) {
    tempBook.display();
  }

  inFile.close();
  return 0;
}

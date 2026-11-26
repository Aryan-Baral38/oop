#include <fstream>
#include <iostream>

using namespace std;

const int TOTAL_RECORDS = 5;

// Function to read a single value at a given record position
void readValue(fstream &file, int pos) {
  file.clear(); // Reset error flags before operation

  if (pos < 0 || pos >= TOTAL_RECORDS) {
    file.setstate(
        ios::failbit); // Mark operation as failed for out-of-bounds positions
  } else {
    file.seekg(pos * sizeof(int), ios::beg);
    int num;
    file.read(reinterpret_cast<char *>(&num), sizeof(int));
  }

  // Check error state using fail()
  if (file.fail()) {
    cout << "Error: Invalid record position (" << pos
         << "). Valid positions are 0 to " << (TOTAL_RECORDS - 1) << ".\n";
    file.clear(); // Clear error state to allow future operations on stream
  } else {
    file.seekg(pos * sizeof(int), ios::beg);
    int num;
    file.read(reinterpret_cast<char *>(&num), sizeof(int));
    cout << "Value at position " << pos << ": " << num << "\n";
  }
}

// Function to modify a single value at a given record position
void modifyValue(fstream &file, int pos, int newVal) {
  file.clear(); // Reset error flags before operation

  if (pos < 0 || pos >= TOTAL_RECORDS) {
    file.setstate(
        ios::failbit); // Mark operation as failed for out-of-bounds positions
  } else {
    file.seekp(pos * sizeof(int), ios::beg);
    file.write(reinterpret_cast<const char *>(&newVal), sizeof(int));
  }

  // Check error state using fail()
  if (file.fail()) {
    cout << "Error: Failed to modify. Position (" << pos
         << ") is out of bounds!\n";
    file.clear(); // Clear error state to allow future operations on stream
  } else {
    cout << "Successfully updated position " << pos << " to " << newVal
         << ".\n";
  }
}

// Helper function to display all records sequentially
void displayAllRecords(fstream &file) {
  file.clear();
  file.seekg(0, ios::beg);
  cout << "\nCurrent file contents: [ ";
  for (int i = 0; i < TOTAL_RECORDS; ++i) {
    int temp;
    file.read(reinterpret_cast<char *>(&temp), sizeof(int));
    cout << temp << " ";
  }
  cout << "]\n";
}

int main() {
  // Open binary stream for both reading and writing (truncating existing
  // content)
  fstream file("numbers.dat", ios::in | ios::out | ios::binary | ios::trunc);

  if (!file) {
    cerr << "Error: Could not create binary file.\n";
    return 1;
  }

  // Initialize the file with 5 integers (e.g., 10, 20, 30, 40, 50)
  int initialData[TOTAL_RECORDS] = {10, 20, 30, 40, 50};
  for (int i = 0; i < TOTAL_RECORDS; ++i) {
    file.write(reinterpret_cast<char *>(&initialData[i]), sizeof(int));
  }

  cout << "Initial binary file 'numbers.dat' created with 5 integers.\n";
  displayAllRecords(file);

  int choice, pos, newVal;

  while (true) {
    cout << "\n-----------------------------\n";
    cout << "1. Read value at position\n";
    cout << "2. Modify value at position\n";
    cout << "3. Display all values\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "Enter record position to read (0-4): ";
      cin >> pos;
      readValue(file, pos);
    } else if (choice == 2) {
      cout << "Enter record position to modify (0-4): ";
      cin >> pos;
      cout << "Enter new integer value: ";
      cin >> newVal;
      modifyValue(file, pos, newVal);
    } else if (choice == 3) {
      displayAllRecords(file);
    } else if (choice == 4) {
      cout << "Exiting program.\n";
      break;
    } else {
      cout << "Invalid menu choice!\n";
    }
  }

  file.close();
  return 0;
}

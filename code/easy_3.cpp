// ARE THERE COMMON FACTORS? 

#include <iostream>

using namespace std;

int main() {
  int a, b;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  int lower = a < b ? a : b;
  int factors = 0;
  for (int i = 1; i <= lower; i++) {
    if (a % i == 0 && b % i == 0) factors++;
  }
  cout << factors;
}

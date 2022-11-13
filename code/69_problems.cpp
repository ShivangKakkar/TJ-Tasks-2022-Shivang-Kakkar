#include <iostream>
#include <math.h>

using namespace std;

int main() {
  cout << "n = ";
  int num;
  cin >> num;

  int digits = 0;
  int temp = num;
  while (temp > 0) {
    temp /= 10;
    digits++;
  }

  temp = num;
  while (digits != 0) {
    digits--;
    int div = pow(10, digits);
    if (temp / div == 6) {
      num += 3 * div;
      break;
    }
    temp -= (temp / div) * div;
  }
  cout << num;
}

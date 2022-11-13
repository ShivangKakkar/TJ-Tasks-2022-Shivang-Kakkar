#include <iostream>

using namespace std;

int main() {
  cout << "n = " << endl;
  int num;
  cin >> num;
  int init = 2;
  bool ans = false;
  while (num >= init) {
    if (num == init) {
      ans = true;
      break;
    }
    init *= 2;
  }
  cout << boolalpha << ans;
}

// NEGATIVE-POSITIVE EXISTENTIAL CRISIS

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cout << "n = ";
  cin >> n;
  int arr[n];
  cout << "Elements of array: ";
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int num = -1;
  for (int i = n - 1; i >= 0; i--) {
    int pos = arr[i];
    for (int j = 0; j < n; j++) {
      int neg = arr[j];
      if (pos != neg && abs(neg) == pos) {
        num = pos;
        break;
      }
    }
    if (num != -1) break;
  }
  cout << num;
}

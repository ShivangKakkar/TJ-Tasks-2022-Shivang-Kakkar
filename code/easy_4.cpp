// TOTAL CUTS

#include <iostream>

using namespace std;

int main() {
  int n, k;
  cout << "n = ";
  cin >> n;
  cout << "k = ";
  cin >> k;
  int arr[n];
  cout << "Elements of array: ";
  for (int i = 0; i < n; i++) cin >> arr[i];
  int cuts = 0;
  for (int i = 0; i < n - 1; i++) {
    int min = arr[n - 1], max = arr[0];
    for (int j = 1; j < n - 1; j++) {
      if (j <= i && arr[j] > max) max = arr[j];
      else if (j > i && arr[j] < min) min = arr[j];
    }
    if (max + min >= k) cuts++;
  }
  cout << cuts;
}

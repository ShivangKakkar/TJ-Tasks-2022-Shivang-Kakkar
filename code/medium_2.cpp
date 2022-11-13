// MINIMUM DIVISION OF GROUPS

#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Enter number of intervals: ";
  cin >> n;
  int arr[n][2];
  cout << "Enter values of each interval (in new line)" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  cout << "intervals = [";
  for (int i = 0; i < n; i++) {
    cout << "[" << arr[i][0] << ", " << arr[i][1] << "]";
    if (i != n - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
  int lower = arr[0][0], upper = arr[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      if (arr[i][j] < lower) lower = arr[i][j];
      if (arr[i][j] > upper) upper = arr[i][j];
    }
  }

  int groups[n][n][2];
  int groupItems[n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      groups[i][j][0] = 0;
      groups[i][j][1] = 0;
    }
  }
  int groupsNum = 0;
  int first = true;
  for (int i = 0; i < n; i++) {
    int x = arr[i][0];
    int y = arr[i][1];
    if (first) {
      groups[0][0][0] = x;
      groups[0][0][0] = y;
      groupsNum++;
      groupItems[0] = 1;
      first = false;
      continue;
    }
    bool works = false;
    for (int j = 0; j < groupsNum; j++) {
      int worksHere = true;
      for (int k = 0; k < groupItems[j]; k++) {
        if (!(y < groups[j][k][0] || x > groups[j][k][1])) {
          worksHere = false;
          break;
        }
      }
      if (worksHere) {
        groups[j][groupItems[j]][0] = x;
        groups[j][groupItems[j]][1] = y;
        groupItems[j]++;
        works = true;
        break;
      }
    }
    if (!works) {
      groups[groupsNum][0][0] = x;
      groups[groupsNum][0][1] = y;
      groupItems[2] = 1;
      groupsNum++;
    }
  }
  cout << groupsNum;
}

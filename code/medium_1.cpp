// MINIMUM DIVISION OF GROUPS

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cout << "Enter value of n: ";
  cin >> n;
  string creators[n];
  string ids[n];
  int views[n];
  cout << "Enter value of each element in creators array: ";
  for (int i = 0; i < n; i++) cin >> creators[i];
  cout << "Enter value of each element in ids array: ";
  for (int i = 0; i < n; i++) cin >> ids[i];
  cout << "Enter value of each element in views array: ";
  for (int i = 0; i < n; i++) cin >> views[i];

  string unique_creators[n];
  int popularity[n];
  string max_view_ids[n];
  for (int i = 0; i < n; i++) popularity[i] = 0;
  int val = 0;
  for (int i = 0; i < n; i++) {
    bool p = false;
    for (int j = 0; j < val; j++) {
      if (unique_creators[j] == creators[i]) {
        p = true;
        break;
      }
    }
    if (p) continue;
    unique_creators[val] = creators[i];
    val++;
  }


  for (int i = 0; i < n; i++) {
    int ind = 0;
    for (int j = 0; j < val; j++) {
      if (creators[i] == unique_creators[j]) {
        ind = j;
        break;
      }
    }
    popularity[ind] += views[i];
  }

  vector<int> maxPop;
  int maxPopInd = 0;
  for (int i = 0; i < val; i++) {
    if (maxPopInd == i) continue;
    if (popularity[maxPopInd] < popularity[i]) {
      maxPopInd = i;
    }
    if (maxPopInd == i) continue;
    if (popularity[maxPopInd] == popularity[i]) {
      maxPop.push_back(maxPopInd);
      maxPopInd = i;
    }
  }
  maxPop.push_back(maxPopInd);

  for (auto i : maxPop) {
    string c = unique_creators[i];
    int maxViewsId = 0;
    for (int j = 0; j < n; j++) {
      if (creators[j] == c && views[j] >= views[maxViewsId]) {
        // Lexicographically changing
        if (views[j] == views[maxViewsId] && ids[maxViewsId][0] < ids[j][0]) continue;
        maxViewsId = j;
      }
    }
    max_view_ids[i] = ids[maxViewsId];
  }
  int winners = maxPop.size();
  string answer[winners][2];
  for (int i = 0; i < winners; i++) {
    answer[i][0] = unique_creators[maxPop[i]];
    answer[i][1] = max_view_ids[maxPop[i]];
  }

  cout << "[";
  for (int i = 0; i < winners; i++) {
    cout << "[\"" << answer[i][0] << "\", \"" << answer[i][1] << "\"]";
    if (i != winners - 1) cout << ", ";
  }
  cout << "]" << endl;
}

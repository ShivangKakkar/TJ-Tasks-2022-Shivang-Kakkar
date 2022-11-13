# TechnoJam Solutions

Programming Language: C++

Code is available here as well in `code` directory.

## DSA (Easy)

### 1) _Power of 2_

**Approach**: Inititalize a number and multiply it by 2 till it is equal or bigger than the input number.

**Code**:

```
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
```

**Screenshots**:

![Screenshot 1](images/easy_1_1st.png)
![Screenshot 2](images/easy_1_2nd.png)

### 2) _69 Problems_

**Approach**: Get total digits. Use that value to divide by a particular power of 10 to get digits starting from left side (instead of the usual right side). Replace first appearance of 6 by subtracting 6`*`10^n and adding 9`*`10^n, or adding 3`*`10^n where n is the place value of digit from left side - 1. Like for 9 in 96, it will be 2 (2nd digit from left) - 1.

**Code**:

```
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
      if (temp/div == 6) {
          num += 3*div;
          break;
      }
      temp -= (temp/div)*div;
  }
  cout << num;
}
```

**Screenshots**:

![Screenshot 1](images/easy_2_1st.png)
![Screenshot 2](images/easy_2_2nd.png)

---

## DSA (Medium)

### 1) _Popular YouTube Creators_

**Approach**: We have 3 arrays of creators, ids and views. Create three new arrays, to store unique creators, their popularity and the id of most seen video. Loop over the first three arrays to fill the values. Now pick out the indexes of popularity array which are highest (can be multiple if equal) into a vector. Use the vector to create a new 2d array named `answers` and save the creator name and views of maximum viewed video respectively. At last display it.

**Code**:

```
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

    for (auto i: maxPop) {
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
        if (i != winners-1) cout << ", ";
    }
    cout << "]" << endl;
}
```

**Screenshots**:

![Screenshot 1](images/medium_1_1st.png)
![Screenshot 2](images/medium_1_2nd.png)

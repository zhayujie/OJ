#include <iostream>
using namespace std;
#include <vector>

int main(void) {
  int n, s;
  vector<int> vec;

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vec.push_back(m);
  }

  int i = 0, j = 0, count = 0;
  int sum = 0, maxCount = 0;
  while (j < vec.size()) {
    sum += vec[j];
    if (sum > s) {
      sum -= vec[i];
      i++;
      j++;
      continue;
    }
    count = j - i + 1;
    maxCount = maxCount > count ? maxCount : count;
    j++;
  }

  cout << maxCount << endl;
}
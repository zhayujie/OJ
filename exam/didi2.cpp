#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// %9 cases AC
int main(void) {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  sort(a, a+n);
  int dp = 1001;
  int globalMin = INT32_MAX;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (dp > 0) {
        index = i;
    }
    dp = (dp + a[i]) < a[i] ? (dp+a[i]) : a[i];
    if (i - index >= 2) {
      globalMin = min(globalMin, dp);
    }
  }
  cout << globalMin << endl;
  
  return 0;
}
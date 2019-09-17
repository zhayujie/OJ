# include <iostream>
# include <cstdio>
using namespace std;

int minCount = INT32_MAX;
bool find(int * dis, bool * vis, int m, int n, int i, int j, int count) {
  if (i >= m || i < 0 || j >= n || j < 0 || vis[i*n+j]) {
    return false;
  }
  count += dis[i*n+j];
  // cout << "i:" << i  << "j: " << j << "dis"<< dis[i*n+j] << " count: " << count << endl; 
  if (i == m-1 && j == n-1) {
    if (count < minCount) {
      minCount = count;
    }
    return true;
  }
  int res = false;
  vis[i*n+j] = true;
  bool r0 = find(dis, vis, m, n, i+1, j, count);
  bool r1 = find(dis, vis, m, n, i, j+1, count);
  bool r2 = find(dis, vis, m, n, j-1, j, count);
  bool r3 = find(dis, vis, m, n, i, j-1, count);
  // if (!r0 && !r1 && !r2 && !r3) {
  //   res = false;
  // } else {
  //   res = true;
  // }
  vis[i*n+j] = false;
  return false;
}


int main(void) {
  int m, n;
  cin >> m;
  cin >> n;
  if (m <= 0 || n <= 0) {
    cout << 0 << endl;
    return 0;
  }
  int dis[m*n];
  bool vis[m*n];
  // cout << "m: " << m << " n: " << n << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // cin >> dis[i*n+j];
      scanf("%d",&dis[i*n+j]);
      vis[i*n+j] = false;
    }
  }
  find(dis, vis, m, n, 0, 0, 0);
  cout << minCount << endl;
}
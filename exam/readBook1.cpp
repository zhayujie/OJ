#include <iostream>
using namespace std;
#include <vector>
/*
输入 m, n, k,  k为障碍物的坐标的个数
5 10 20
1 4
0 3
*/

int minCount = INT32_MAX;
int find(int i, int j, int n, int m, vector<bool> visited, vector<bool> bad, int count) {
  if (i < 0 || i > n-1 || j < 0 || j > m -1 || visited[i*m+j] || bad[i*m+j]) {
    // cout << "走不通了: " << "i: " << i << " j: " << j << endl;
    return 0;
  }
  cout << "i: " << i << " j: " << j << " count:" << count << endl;

  if (i == n-1 && j == m-1) {
    if (count < minCount) {
      cout << "到达终点, count= " << count << endl;
      minCount = count;
    }
    return -1;
  }
  int res = 0;
  visited[i*m+j] = true;
  
  int res1 = find(i-1, j, n, m, visited, bad, count+1);
  int res2 = find(i, j-1, n, m, visited, bad, count+1);
  int res3 = find(i+1, j, n, m, visited, bad, count+1);
  int res4 = find(i, j+1, n, m, visited, bad, count+1);
  if (res1 == 0 && res2 == 0 && res3 == 0 && res4 == 0) {
    res = 0;
  } else {
    res = -1;
  }
  // if (res == 0) {
  //   visited[i*m+j] = false;
  // }
  visited[i*m+j] = false;
  return res;
}


int main(void) {
  int n, m, k;
  int ki, kj;

  cin >> n >> m >> k; 
  vector<bool> bad(m*n);
  vector<bool> visited(m*n);
  // cout << bad.size() << endl;

  for (int i = 0; i < k; i++) {
    cin >> ki >> kj;
    bad[ki * m + kj] = true; 
    // cout << ki * m + kj << endl; 
  }
  int count = 0;
  int res = find(0, 0, n, m, visited, bad, 0);
  // cout << "m: " << m << " n: " << n << "k: " << k;
  if (res == 0) {
    cout << 0 << endl;
  } else {
    cout << minCount << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    4.对一个大小为n的正整数 数组，做k次以下操作：
      (1) 找到最小非0正数x，输出
      (2) 对数组所有非0正数 -x
*/

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        vec.push_back(v);
    }
    sort(vec.begin(), vec.end());
    int count = 0;
    int p = 0;
    for (int i = 0; i < k;) {
        if (p == vec.size()) {
            cout << 0 << endl;
            i++;
            continue;
        }
        int m = vec[p] - count;
        count += m;
        p++;
        if (m != 0) {
            cout << m << endl;
            i++;
        }
    }

    return 0;
}
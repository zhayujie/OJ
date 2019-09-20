#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 两个数组分成两半(数量相差不超过1)，两数组和的差值最小
void printPower(vector<int> &vec, int sum) {
    int len = vec.size();
    int dp[len+1][sum/2+1];
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= sum/2; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j<= sum/2; j++) {
            if (j >= vec[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-vec[i-1]] + vec[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int v1 = dp[len/2][sum/2];
    int v2 = sum - v1;
    cout << min(v1, v2) << " " << max(v1, v2) << endl;
    return;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, sum = 0;
        vector<int> vec;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
            vec.push_back(p);
            sum += p;
        }
        printPower(vec, sum);
    }
    return 0;
}
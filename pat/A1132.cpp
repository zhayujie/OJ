#include <iostream>
#include <cmath>
using namespace std;

//计算整数的位数
int count_bit(int x) {
    int count = 0;
    while (x > 0) {
        x /= 10;
        count++;
    }
    return count;
}

int main(void) {
    int n, z, i;
    
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> z;
        int mid = count_bit(z) / 2;
        int t = pow(10, mid);
        // z % t == 0 会产生浮点错误，比如当 z = 1000 时
        if (z % t > 0 && z % ((z % t) * (z / t)) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}

#include <iostream>
using namespace std;
bool marked[10010];						//注意9973的下一个素数是10007
//判断是否是素数的函数
bool is_prime(int x) {
    if (x < 2)		return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main(void) {
    int msize, n, num, i;
    
    cin >> msize >> n;
    for (i = msize; ; i++) {
        if (is_prime(i)) {
            msize = i;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        cin >> num;
        int h = num % msize;				//初始散列位置
        int hash = h;
        bool flag = false;					//是否散列成功
        for (int k = 0; k < msize; k++) {
            hash = (h + k * k) % msize;		//二次探测法
            if (!marked[hash]) {			//成功找到位置
                marked[hash] = true;
                flag = true;
                break;
            }
        }
        if (flag)		cout << hash;
        else			cout << "-";
        if (i != n-1)   cout << " ";
        else            cout << endl;
    }
    
    return 0;
}

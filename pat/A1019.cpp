#include <iostream>
#include <math.h>
using namespace std;
bool is_prime(int x);

int main(void) {
    int num;
    int i = 2;
    bool first = true;
    
    cin >> num;
    cout << num << "=";
    if (num == 1) {								//输入为1时，输出 1=1
        cout << 1 << endl;
        return 0;
    }
    if (is_prime(num)) {						//输入素数时，直接输出无需分解
        cout << num << endl;
        return 0;
    }
    while (num >= i) {
        int count = 0;
        while (num % i == 0) {
            num /= i;							//num值越来越小
            count++;							//当前质数因子的数量
        }
        if (count > 0) {
            if (!first)    cout << "*";			//第一次输出不需要*号
            if (count == 1)
                cout << i;
            else
                cout << i << "^" << count;
            first = false;
            //在每次分解后都需要判断此时的数是否为质数，如果是则直接结束
            if (is_prime(num)) {
                cout << "*" << num << endl;
                return 0;
            }
        }
        else {
            while (!is_prime(++i))				//寻找下一个素数因子
                continue;
        }
    }
    cout << endl;
    
    return 0;
}

bool is_prime(int x) {
    if (x < 2)		return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

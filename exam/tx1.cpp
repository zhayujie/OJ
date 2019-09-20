#include <iostream>
using namespace std;
/*
    1.给一个字符串，判断能不能通过删除操作使其变为，开头为8，个数为11的字符串  easy
*/

void judge(int len, string st) {
    len = st.size();
    if (len < 11 || (len == 11 && st[0] != '8')) {
        cout << "NO" << endl;
        return;
    }
    int i = 0;
    for (; i < len; i++) {
        if (st[i] == '8') {
            break;
        }
    }
    if (len - i >= 11) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;
    }
    return;
}

int main(void) {
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st;
        int len;
        cin >> len >> st;
        judge(len, st);
    }

    return 0;
}
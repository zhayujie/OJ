#include <iostream>
#include <stdio.h>
#include <string.h>
#define SIZE 257
using namespace std;
char st[100][SIZE];
char *ps[100];
char suffix[SIZE];

int main(void) {
    int n, i;
    
    cin >> n;
    getchar();
    int min_len = SIZE;
    for (i = 0; i < n; i++) {
        gets(st[i]);
        int len = strlen(st[i]);
        ps[i] = st[i] + len - 1;
        if (len < min_len)   min_len = len;
    }
    int count = 0;
    bool all_same = true;
    while (count < min_len) {
        for (i = 1; i < n; i++) {
            if (*ps[i] != *ps[0]) {
                all_same = false;
                break;
            }
            ps[i]--;
        }
        if (!all_same)      break;
        ps[0]--;
        count++;
    }
    if (count == 0)
        cout << "nai" <<endl;
    else {
        char * p = st[0] + strlen(st[0]) - count;
        while (*p)
            cout << *p++;
        cout << endl;
    }
    
    return 0;
}

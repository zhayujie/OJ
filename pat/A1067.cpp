#include <cstdio>
using namespace std;
int a[100000];
int index[100000];

void swap(int x, int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
    index[a[x]] = x;
    index[a[y]] = y;
}

int main(void) {
    int n;                      //数字个数
    int t = 0;                  //需要进行交换的数的个数
    int count = 0;              //swap()交换次数

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a[i] = num;
        index[num] = i;
        if (num != i && num != 0)
            t++;
    }
    int k = 1;                  //第一个不匹配的数的索引
    while (t > 0) {
        if (a[0] == 0) {
            for (int i = k; i < n; i++) {
                if (i != a[i]) {
                    k = i + 1;
                    swap(0, i);
                    count++;
                    break;
                }
            }
        }
        swap(index[0], index[index[0]]);
        t--;
        count++;
    }
    printf("%d\n", count);
    
    return 0;
}

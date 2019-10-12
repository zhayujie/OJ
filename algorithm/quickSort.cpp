# include <iostream>
#include <stdio.h>
using namespace std;

void qsort(int* a, int lo, int hi) {
    if (lo >= hi)   return;
    int i = lo, j = hi+1;
    int v = a[lo];
    while (true) {    
        // 从左往右找到第一个大于等于v的
        while (a[++i] < v) {
            if (i >= hi)    break;
        }
        // 从右往左找到第一个小于等于v的
        while (a[--j] > v) {
            continue;
        }
        if (i >= j)         break;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    // 交换切分点
    // cout << "i: " << i << " j: " << j << endl;

    int temp = a[lo];
    a[lo] = a[j];
    a[j] = temp;

    // 对左子数组排序
    qsort(a, lo, j-1);
    // 对右子数组排序
    qsort(a, j+1, hi);
}

int main(void) {
    int a[10] = {10,3,4,8,23,3,1,9,1,2};
    qsort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
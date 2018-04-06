#include <cstdio>
#include <algorithm>
int n;						//节点个数
int index = 0;				//序列数组的索引
int a[1005];				//输入的序列数组
int node[1005];				//完全二叉树数组
using namespace std;

void travel(int i) {
    if (i > n)  return;
    travel(2*i);
    node[i] = a[index++];
    travel(2*i+1);
}

int main(void) {
    int i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    travel(1);				//中序遍历构造完全二叉树
    //层次遍历输出
    for (i = 1; i < n; i++)
        printf("%d ", node[i]);
    printf("%d\n", node[i]);

    return 0;
}

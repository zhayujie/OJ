#include <stdio.h>
struct node {
    int ad;
    int val;
    int next;
} node1[100000], node2[100000];

int main(void) {
    int first, count, k, i, j;
    int n = 0;						//节点数量，输入中可能有无效节点，n <= count
    int	m, r;
    struct node x;

    scanf("%d%d%d", &first, &count, &k);
    for (i = 0; i < count; i++) {
        scanf("%d%d%d", &x.ad, &x.val, &x.next);
        node1[x.ad] = x;
    }
    for (i = 0, j = first; j != -1; j = node1[j].next, i++) {
        node2[i] = node1[j];
        n++;						//节点数量需要重新计算
    }
    
    m = n / k;						//周期数
    r = n % k;						//剩余不足一周期的节点数（正序输出）
    
    //先把需要倒序的m个周期节点输出
    for (i = 0; i < m; i++) {
        for (j = (i+1)*k-1; j >= i*k; j--) {
            //首节点只需要输出该节点地址和值
            if (j == k-1)
                printf("%05d %d ", node2[j].ad, node2[j].val);
            //其余节点要输出两次地址（其中一次作为上一个的next）和一次值
            else
                printf("%05d\n%05d %d ", node2[j].ad, node2[j].ad, node2[j].val);
        }
    }

    //处理剩余正序输出的r个节点
    for (j = m * k; j < n; j++) {
        //当 n < k 时，全部正序输出，首节点只需输出一个地址
        if (j != 0)				printf("%05d\n", node2[j].ad);
        printf("%05d %d ", node2[j].ad, node2[j].val);
    }
    printf("-1\n");					//尾节点的next

    return 0;
}

/*开始好傻，还用递归来给输入节点的序号
    其实是按顺序输入每个节点的左右序号
    1.中序遍历把排序后的数值安排上了
    2.利用队列层次遍历输出*/
            
#pragma warning (disable: 4786)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
    int val;
    int left;
    int right;
} Node;
Node node[100];
int value[100];
int cont = 0;
void travel(int v);
//void dfs(int v);

int main(void) {
    int n, i;
    
    cin >> n;
    //dfs(0);
    for (i = 0; i < n; i++)
        cin >> node[i].left >> node[i].right;
    for (i = 0; i < n; i++)
        cin >> value[i];
    
    sort(value, value+n);
    travel(0);
    
    queue<int> q;
    q.push(0);
    cout << node[0].val;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (node[v].left != -1)			q.push(node[v].left);
        if (node[v].right != -1)		q.push(node[v].right);
        if (v != 0)     cout << " " << node[v].val;
    }
    cout << endl;
    
    return 0;
}

void travel(int v) {
    if (v == -1)    return;
    travel(node[v].left);
    node[v].val = value[cont++];
    travel(node[v].right);
}
/*
void dfs(int v) {
    if (v == -1)    return;
    int l, r;
    cin >> l >> r;
    node[v].left = l;
    node[v].right = r;
    dfs(l);
    dfs(r);
    return;
}
*/

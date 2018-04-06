#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} Node;
Node * root;								//根节点
int num_black;								//黑色节点数量
bool is_red_black;							//是否是红黑树

//动态分配新的节点
Node * new_node(int val) {
    Node * p = (Node *) malloc(sizeof(Node));
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

//添加节点
Node * add_node(Node * node, int val) {
    if (node == NULL)   return new_node(val);
    if (abs(val) < abs(node->val))
        node->left = add_node(node->left, val);
    else
        node->right = add_node(node->right, val);
    return node;
}
void add(int val) {
    root = add_node(root, val);
}

//先序遍历
void travel(Node * node, int num) {
    if (!is_red_black)      return;			//如果已经发现不是红黑树，停止后面的递归
    if (node == NULL) {						//遍历到NULL以后，判断路径中的黑色节点数是否与之前一致
        if (num_black == 0)
            num_black = num;
        else if (num_black != num)
            is_red_black = false;
        return;
    }
    if (node->val < 0) {					//红色节点：子节点必须为黑色节点（或NULL）
        if ((node->left != NULL && node->left->val < 0) || (node->right != NULL && node->right->val < 0))
            is_red_black = false;
    }
    else									//黑色节点：计数+1
        num++;
    travel(node->left, num);
    travel(node->right, num);
}

int main(void) {
    int k, n, i, j;
    
    cin >> k;
    for (i = 0; i < k; i++) {
        root = NULL;
        num_black = 0;
        is_red_black = true;
        
        cin >> n;
        //创建二叉树
        for (j = 0; j < n; j++) {
            int v;
            cin >> v;
            add(v);
        }
        if (root->val < 0)					//红黑树根节点为黑色
            is_red_black = false;
        travel(root, 0);
        if (is_red_black)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    return 0;
}

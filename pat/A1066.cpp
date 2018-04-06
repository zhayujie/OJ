#include <cstdio>
#include <cstdlib>
#define max(x, y) (((x) > (y)) ? (x) : (y))
typedef struct tnode
{
    int val;
    struct tnode * left;
    struct tnode * right;
} node;

//LL：右旋转
node * rotate_right(node * root) {
    node * lnode = root->left;
    root->left = lnode->right;
    lnode->right = root;
    return lnode;
}

//RR：左旋转
node * rotate_left(node * root) {
    node * rnode = root->right;
    root->right = rnode->left;
    rnode->left = root;
    return rnode;
}

//LR：先左旋转，再右旋转
node * rotate_left_right(node * root) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
}

//RL：先右旋转，再左旋转
node * rotate_right_left(node * root) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
}

//递归求得以root为根节点的树的高度
int get_height(node * root) {
    if (root == NULL)   return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
}

//在以root为根节点的树中插入值为val的节点
node * insert(node * root, int val) {
    if (root == NULL) {
        root = (node *) malloc(sizeof(node));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
    } else if (val < root->val) {
        root->left = insert(root->left, val);
        if (get_height(root->left) - get_height(root->right) == 2) {
            if (val < root->left->val)      root = rotate_right(root);
            else                            root = rotate_left_right(root);
        }
    } else {
        root->right = insert(root->right, val);
        if (get_height(root->right) - get_height(root->left) == 2) {
            if (val > root->right->val)     root = rotate_left(root);
            else                            root = rotate_right_left(root);
        }
    }

    return root;
}


int main(void) {
    int n, val;
    node * root = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d\n", root->val);

    return 0;
}

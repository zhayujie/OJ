#include <cstdio>
#include <vector>
using namespace std;
typedef struct{
    int add;
    int val;
    int next;
}Node;
Node node[100000];

int main(void) {
    int first, n, k, i;
    vector<Node> vec1, vec2;
    Node x;
    
    scanf("%d%d%d", &first, &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &x.add, &x.val, &x.next);
        node[x.add] = x;
    }
    bool is_first = true;
    //输出小于 0 的部分
    for (i = first; i != -1; i = node[i].next) {
        if (node[i].val < 0) {
            if (is_first) {
                printf("%05d %d ", node[i].add, node[i].val);
                is_first = false;
            }
            else
                printf("%05d\n%05d %d ", node[i].add, node[i].add, node[i].val);
        }
        else if (node[i].val <= k)
            vec1.push_back(node[i]);
        else
            vec2.push_back(node[i]);
    }
    
    //输出 [0, k] 的部分
    for (i = 0; i < vec1.size(); i++) {
        if (is_first) {
            printf("05d %d ", vec1[i].add, vec1[i].val);
            is_first = false;
        }
        else
            printf("%05d\n%05d %d ", vec1[i].add, vec1[i].add, vec1[i].val);
    }
       
    //输出大于 k 的部分
    for (i = 0; i < vec2.size(); i++) {
        if (is_first) {
            printf("%05d %d ", vec2[i].add, vec2[i].val);
            is_first = false;
        }
        else
            printf("%05d\n%05d %d ", vec2[i].add, vec2[i].add, vec2[i].val);
    }
    printf("-1\n");
    
    return 0;
}

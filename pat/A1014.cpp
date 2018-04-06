#pragma warning (disable: 4786)
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef struct {
    int id;             //经销商的id
    int num;            //商品数量
} retailer;
int father[100000];		//该节点的父节点
int level[100000];		//该节点所处层数
int get_level(int id);

int main(void) {
    int n, i, j;
    double p, r;
    vector<retailer> vec;
    vector<retailer>::iterator iter;
    
    cin >> n >> p >> r;
    int k, num, id;
    for (i = 0; i < n; i++) {
        cin >> k;
        if (k == 0) {
            cin >> num;
            retailer re;
            re.id = i;
            re.num = num;
            vec.push_back(re);
        }
        else {
            for (j = 0; j < k; j++) {
                cin >> id;
                father[id] = i;
            }
        }
    }
    double total = 0;;
    for (iter = vec.begin(); iter != vec.end(); iter++) {
    /*
    //开始用从每个叶子节点迭代回根节点求深度，会超时
        int count = 0;
        for (i = iter->id; i != 0; i = father[i])
            count++;
        total += (iter->num) * p * pow(1 + r/100, count);
    */

        total += (iter->num) * p * pow(1 + r/100, get_level(iter->id));
    }
    printf("%.1f\n", total);
    
    return 0;
}

//获取节点的层数
int get_level(int id) {
    if (id == 0)		return 0;
    if (level[id] == 0)
        level[id] = get_level(father[id]) + 1;
    return level[id];
}


/*	另一种思路：dfs遍历此树


typedef struct {
    int num;                //如果是叶子节点则表示销售量
    vector<int> child;      //该节点的所有子节点
} node;
vector<node> v;             //树中节点的集合

dfs(0, 0);
void dfs(int id, int depth) {
    if (v[id].child.size() == 0) {						 //表明是叶子节点
        sum += v[id].num * p * pow(1 + r/100, depth);
        return;
    }
    for (int i = 0; i < v[id].child.size(); i++)
        dfs(v[id].child[i], depth + 1);					//进入下一层深度加1
    return;
}
*/

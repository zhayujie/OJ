#pragma warning(disable: 4786)
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main(void) {
    int n, i, j;
    
    scanf("%d", &n);
    vector<set<int> > vec(n);
    set<int>::iterator iter;
    int m, num;
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%d", &num);
            vec[i].insert(num);
        }
    }
    int k, a, b;
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        int nc = 0, nt = vec[b-1].size();
        for (iter = vec[a-1].begin(); iter != vec[a-1].end(); iter++) {
            if (vec[b-1].count(*iter))                  //if (vec[b-1].find(*iter) != vec[b-1].end())
                nc++;
            else
                nt++;
        }
    //  nt = vec[a-1].size() + vec[b-1].size() - nc;	//这样计算可能会超时
        printf("%.1f%%\n", nc * 1.0 / nt * 100);
    }
    
    return 0;
}

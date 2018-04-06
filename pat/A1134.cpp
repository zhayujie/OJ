#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(void) {
    int n, m, i, j;
    
    cin >> n >> m;
    vector<vector<int> > edge(n);
    for (i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        edge[v].push_back(i);
        edge[w].push_back(i);
    }
    
    int k, nv, ver, t;
    set<int> s;
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> nv;
        for (j = 0; j < nv; j++) {
            cin >> ver;
            for (t = 0; t < edge[ver].size(); t++)
                s.insert(edge[ver][t]);
        }
        if (s.size() == m)  cout << "Yes" << endl;
        else                cout << "No" << endl;
        s.clear();                  //清空set集合
    }
    
    return 0;
}

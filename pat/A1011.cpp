#pragma warning (disable: 4786)
#include <iostream>
#include <queue>
#define MAXN 1001
using namespace std;
int net[MAXN][MAXN];
int level[MAXN];
int marked[MAXN];
int main(void) {
    int n, l;
    
    cin >> n >> l;
    int m, i, j, x;
    for (i = 1; i <= n; i++) {
        cin >> m;
        for (j = 0; j < m; j++) {
            cin >> x;
            net[x][i] = 1;
        }
    }
    int s, k, max;
    queue<int> q;
    cin >> k;
    for (i = 0; i < k; i++) {
        for (j = 1; j <= n; j++)
            marked[j] = 0;
        cin >> s;
        q.push(s);
        level[s] = 0;
        marked[s] = 1;
        max = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (level[v] == l)      continue;
            for (int w = 1; w <= n; w++) {
                if (net[v][w] && !marked[w]) {
                    q.push(w);
                    max++;
                    marked[w] = 1;
                    level[w] = level[v] + 1;
                }
            }
        }
        cout << max << endl;
    }
    
    return 0;
}

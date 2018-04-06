//dfs
#include <stdio.h>
#include <limits.h>
#define MAXN 501
int num[MAXN];
int s[MAXN][MAXN];
int marked[MAXN];
int next[MAXN];
int path[MAXN];
int n, c, sp;
int ns, nb, nt;
int n_sent = INT_MAX, n_back = INT_MAX, t_path = INT_MAX;
void cal(int i);
void dfs(int v);
 
int main(void) {
    int m, i, j, v, w, time;
    int count = 0;
      
    scanf("%d%d%d%d", &c, &n, &sp, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &v, &w, &time);
        s[v][w] = time;
        s[w][v] = time;
    }
    dfs(0);
    
    printf("%d ", n_sent);
    for (i = 0; path[i] != sp; i++) {
        printf("%d->", path[i]);
    }
    printf("%d ",  sp);
    printf("%d\n", n_back);
   
    return 0;
}
 
void dfs(int v) {
    int i, t, count;
 
    marked[v] = 1;
    for (i = 0; i <= n; i++) {
        if (v == sp)    break;
        t = s[v][i];
        if (t > 0 && !marked[i]) {
            next[v] = i;
            dfs(i);
        }
    }
    marked[v] = 0;                          //回溯，取消标记
    if (v != sp)    return;
    nt = 0;
    ns = 0;
    nb = 0;
    for (i = 0; i != sp; i = next[i]) {
        nt += s[i][next[i]];
        if (i == 0) continue;
        cal(i);
    }
    cal(sp);
    if (nt > t_path)    return;
    if (nt == t_path) {
        if (ns < n_sent || (ns == n_sent && nb < n_back)) {
 
        }
        else return;
    }
    n_sent = ns;
    n_back = nb;
    t_path = nt;
    for (i = 0, count = 0; i != sp; i = next[i]) {
        path[count++] = i;
    }
    path[count] = sp;
}
 
void cal(int i) {
    int x;
 
    if (num[i] > c/2)
        nb += num[i] - c/2;
    else if (num[i] < c/2) {
        x = nb - (c/2 - num[i]);
        if (x >= 0)
            nb = x;
        else {
            ns += -x;
            nb = 0;
        }
    }
}

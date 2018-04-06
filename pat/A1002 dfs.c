#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXN 201

void dfs(int v);
int get_index(char * st);

int s[MAXN][MAXN];
char spot[MAXN][5];
int happy[MAXN];
int marked[MAXN];
int next[MAXN];
int path[MAXN];
int n, dst;
int n_least = 0;
int max_happy = 0;
int least_cost = INT_MAX;
double max_ever = 0;

int main(void) {
    int k, i, cost, v, w;
    char s1[5], s2[5];

    scanf("%d%d%s", &n, &k, spot[0]);
    for (i = 1; i < n; i++)
        scanf("%s%d", spot[i], &happy[i]);
    for (i = 0; i < k; i++) {
        scanf("%s%s%d", s1, s2, &cost);
        v = get_index(s1);
        w = get_index(s2);
        s[v][w] = cost;
        s[w][v] = cost;
    }
    dst = get_index("ROM");
    dfs(0);
    
    printf("%d %d %d %d\n", n_least, least_cost, max_happy, (int) max_ever);
    for (i = 0; path[i] != dst; i++)
        printf("%s->", spot[path[i]]);
    printf("%s\n", spot[dst]);
    
    return 0;
}

void dfs(int v) {
    int i, j, cost, happiness, t;
    double ever;
    
    marked[v] = 1;
    for (i = 0; i < n; i++) {
        if (v == dst)   break;
        if (s[v][i] > 0 && !marked[i]) {
            next[v] = i;
            dfs(i);
        }
    }
    marked[v] = 0;
    if (v != dst)   return;
    
    cost = 0;
    happiness = 0;
    t = 0;
    for (i = 0; i != dst; i = next[i]) {
        cost += s[i][next[i]];
        t++;
        if (i == 0)  continue;
        happiness += happy[i];
    }
    happiness += happy[dst];
    ever = happiness * 1.0 / t;
    if (cost > least_cost)  return;
    else if (cost < least_cost) {
        n_least = 1;
        least_cost = cost;
    }
    else {
        n_least++;
        if (happiness < max_happy)  return;
        if (happiness == max_happy && ever < max_ever)
            return;
    }
    max_happy = happiness;
    max_ever = ever;
    
    for (i = 0, j = 0; i != dst; i = next[i])
        path[j++] = i;
    path[j] = dst;
}

int get_index(char * st) {
    int i;
    
    for (i = 0; i < n; i++)
        if (strcmp(spot[i], st) == 0)
            break;
    
    return i;
}

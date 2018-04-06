#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXN 201

void dfs(int v);
int get_index(char * st);
int min();
void relax(int v);

char spot[MAXN][5];
int s[MAXN][MAXN];
int happy[MAXN];
int marked[MAXN];
int edgeTo[MAXN];
int distTo[MAXN];
int path_happy[MAXN];
int path_count[MAXN];
int path[MAXN];
int n_path[MAXN];
int n, dst;

int main(void) {
    int k, i, cost, v, w, x;
    int count = 0;
    char s1[5], s2[5];

    for (i = 1; i < MAXN; i++) {
        distTo[i] = INT_MAX;
    }

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

    n_path[0] = 1;
    distTo[0] = 0;
    relax(0);
    while ((x = min()) != dst) {
        relax(x);
    }
    printf("%d %d %d %d\n",  n_path[dst], distTo[dst], path_happy[dst], path_happy[dst] / path_count[dst]);
    for (i = dst; i != 0; i = edgeTo[i])
        path[count++] = i;
    path[count] = 0;
    for (i = count; i > 0; i--)
        printf("%s->", spot[path[i]]);
    printf("%s\n", spot[dst]);
    
    return 0;
}

void relax(int v) {
    int i, t;
    
    marked[v] = 1;
    for (i = 0; i < n; i++) {
        t = s[v][i];
        if (t == 0 || marked[i])     continue;

        if (distTo[i] < distTo[v] + t)
            continue;
        
        if (distTo[i] > distTo[v] + t) {
            n_path[i] = n_path[v];
        }
        if (distTo[i] == distTo[v] + t) {
            n_path[i] += n_path[v];
            if (path_happy[i] > path_happy[v] + happy[i])
                continue;
            else if (path_happy[i] == path_happy[v] + happy[i]) {
                if (path_count[i] < path_count[v] + 1)
                    continue;
            }
        }
        distTo[i] = distTo[v] + t;
        edgeTo[i] = v;
        path_happy[i] = path_happy[v] + happy[i];
        path_count[i] = path_count[v] + 1;
    }
}

int get_index(char * st) {
    int i;
    
    for (i = 0; i < n; i++)
        if (strcmp(spot[i], st) == 0)
            break;
    
    return i;
}

int min() {
    int i, min_index;
    int min = INT_MAX;
     
    for (i = 1; i <= n; i++) {
        if (!marked[i] && distTo[i] < min) {
            min = distTo[i];
            min_index = i;
        }
    }
     
    return min_index;
}

/*
    错误：
    数组全部初始化为一个数只能通过循环
    int distTo[MAXN] = {-1};	只会让distTo[0] = -1;
 */

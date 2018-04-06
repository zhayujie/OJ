#include <stdio.h>
#include <limits.h>
#define MAXN 501
 
int num[MAXN];						//各点的车数
int s[MAXN][MAXN];					//邻接矩阵表示图
int marked[MAXN];					//标记已被放松过的顶点
int distTo[MAXN];					//各点相对于起点的距离
int next[MAXN];						//下一个顶点
int path[MAXN];						//符合要求的最短路径
  
void relax(int v);
int min();
void dfs(int v);
void cal(int i);
 
int n, c, sp;
int ns, nb;
//带出车的最小辆数 和 带回车的最小辆数
int n_sent = INT_MAX, n_back = INT_MAX;
  
int main(void) {
    int m, i, v, w, time;
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
    for (i = 1; i <= n; i++)
        distTo[i] = INT_MAX;			//初始化各顶点到起点的距离
    distTo[0] = 0;
    while (!marked[sp]) {				//当sp已经被放松，则说明最短路径已找到
        relax(min());
    }
    dfs(sp);
 
    printf("%d ", n_sent);
    for (i = 0; path[i] != sp; i++) {
        printf("%d->", path[i]);
    }
    printf("%d ",  sp);
    printf("%d\n", n_back);
   
    return 0;
}
  
void relax(int v) {
    int i, t;
      
    marked[v] = 1;
    for (i = 0; i <= n; i++) {
        t = s[v][i];
        if (t == 0 || marked[i])      continue;
        if (distTo[i] > distTo[v] + t) {
            distTo[i] = distTo[v] + t;
        }
    }
}
  
void dfs(int v) {
    int i, count, t;
     
    for (i = 0; i <= n; i++) {
        t = s[v][i];
        //只访问已被标记过的顶点而且 该点必须是在其中一条最短路径上
        if (t == 0 || !marked[i] || (distTo[i] + t != distTo[v]))	continue;
        next[i] = v;
        dfs(i);
    }
    if (v != 0)     return;
    
    ns = 0;				//需要从起点携带的车数
    nb = 0;				//当前身上的车数
    for (i = next[0]; i != sp; i = next[i]) {
        cal(i);
    }
    cal(sp);
    //当前这条最短路径与已经保存的最优解比较，判断是否需要更新最优路径
    if (ns < n_sent || (ns == n_sent && nb < n_back)) {
        count = 0;
        n_sent = ns;
        n_back = nb;
        for (i =  0; i != sp; i = next[i]) {
            path[count++] = i;
        }
        path[count] = sp;
    }
}

//计算到达每一个点时 要从起点携带的车数(是一直累加的) 和 当时身上的车数(要带回的车数)
void cal(int i) {
    int x;
 
    if (num[i] > c/2)					//此站车多，从中取出
        nb += num[i] - c/2;
    else if (num[i] < c/2) {			//此站车少，补充放入
        x = nb - (c/2 - num[i]);
        if (x >= 0)
            nb = x;
        else {							//身上的不够，起点携带数增加
            ns += -x;
            nb = 0;
        }
    }
}
 
//找到距离起点最短的点，即下一个需要放松的点
int min() {
    int i, min_index;
    int min = INT_MAX;
      
    for (i = 0; i <= n; i++) {
        if (!marked[i] && distTo[i] < min) {
            min = distTo[i];
            min_index = i;
        }
    }
      
    return min_index;
}

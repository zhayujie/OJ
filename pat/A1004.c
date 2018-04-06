#include <stdio.h>

int a[60][1286][128];
int marked[60][1286][128];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int count;

void dfs(int i, int j, int k);

int main(void) {
    int m, n, l, t, i, j, k;
    int volume = 0;
    
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (i = 0; i < l; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                scanf("%d", &a[i][j][k]);
            }
        }
    }
    
    for (i = 0; i < l; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                if (a[i][j][k] == 1 && !marked[i][j][k]) {
                    count = 0;

                    dfs(i, j, k);
                    
                    if (count >= t)
                        volume += count;
                }
            }
        }
    }
    printf("%d\n", volume);
}

void dfs(int i, int j, int k) {
    int t, x, y, z;

    marked[i][j][k] = 1;
    if (a[i][j][k] == 0 )
        return;
    count++;
    for (t = 0; t < 6; t++) {
        x = i+dx[t];
        y = j+dy[t];
        z = k+dz[t];
        if (x >= 0 && y >= 0 && z >= 0 && !marked[x][y][z])
            dfs(x, y, z);
    }
    return;
}

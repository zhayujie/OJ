#include <cstdio>
int main(void) {
    int g1, s1, k1, g2, s2, k2, g3, s3, k3, t;
    
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    k3 = (k1 + k2) % 29;
    t = s1 + s2 + (k1 + k2) / 29;
    s3 = t % 17;
    g3 = g1 + g2 + t / 17;
    printf("%d.%d.%d\n", g3, s3, k3);
    
    return 0;
}

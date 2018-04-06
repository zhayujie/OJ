#include <cstdio>
int main(void) {
    int t, i;
    long a, b, c, d;
    
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%ld%ld%ld", &a, &b, &c);
        d = a + b;
        printf("Case #%d: ", i);
        if (a < 0 && b < 0 && d >= 0) {
            printf("false\n");
        }
        else if (a > 0 && b > 0 && d < 0) {
            printf("true\n");
        }
        else if (a + b > c) {
            printf("true\n");
        }
        else {
            printf("false\n");
        }
    }
    
    return 0;
}

#include <stdio.h>
int main(void) {
    int a, b, c;
    int n;
    char sum[32] = {'\0'};
    int m = 0;
    int i = 30;
    char * p = sum;
    
    scanf("%d%d%d", &a, &b, &n);
    c = a + b;
    
    while (c > 0) {
        sum[i--] = c % n + '0';
        c /= n;
    }
    while (*p == '\0') {
        p++;
    }
    printf("%s\n", p);
    
    return 0;
}


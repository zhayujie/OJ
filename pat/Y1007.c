#include <stdio.h>
int main(void) {
    char a[1001];
    char b[1001];
    
    int n;
    char * st;
    int x;
    int r;
    int i = 0;
    
    scanf("%s%d", a, &n);
    st = a;

    if (a[1] == '\0') {
        printf("%d %d\n", (a[0] - '0') / n, (a[0] - '0') % n);
        return 0;
    }
    if (*st - '0' < n)
        r = *st++ - '0';
    else
        r = 0;
    i = 0;
    while (*st) {
        x = r * 10 + (*st - '0');
        r = x % n;
        b[i++] = x / n + '0';
        st++;
    }
    b[i] = '\0';
    printf("%s %d\n", b, r);
    
    return 0;
}

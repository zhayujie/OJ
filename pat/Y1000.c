#include <stdio.h>
int main(void) {
    int n;
    long a, b, c;
    int sum;
    int i = 0;
     
    scanf("%d", &n);
    while (i++ < n) {
        scanf("%ld%ld%ld", &a, &b, &c);
         
        if (a + b > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
     
    return 0;
}

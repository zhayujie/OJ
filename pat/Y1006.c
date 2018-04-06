#include <stdio.h>
int main(void) {
    int a, m, n, b;
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
  

    scanf("%d%d%d%d", &a, &m, &b, &n);
   
    
    while (a != 0) {
        if (a % 10 == m)
            sum1 = 10 * sum1 + m;
        a /= 10;
    }
    
    while (b != 0) {
        if (b % 10 == n)
            sum2 = 10 * sum2 + n;
        b /= 10;
    }
    printf("%d\n", sum1 + sum2);
    
    return 0;
}

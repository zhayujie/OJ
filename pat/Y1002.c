#include <stdio.h>
int isPrime(int x);
int main(void) {
    int m, n;
    int d = 0;
    int i = 1;
    int count = 0;
    
    scanf("%d%d", &m, &n);
    
    while(1) {
        i++;
        if (isPrime(i)) {
            count++;
            if (count >= m) {
                d++;
                if (d != 0 && d % 10  == 0)
                    printf("%d\n", i);
                else if (count < n)
                    printf("%d ", i);
                else
                    printf("%d\n", i);
            }
            if (count == n) {
                return 0;
            }
          
        }
    }
    
    return 0;
}

int isPrime(int x) {
    int i;
    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

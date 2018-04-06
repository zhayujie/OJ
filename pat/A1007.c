#include <stdio.h>
#include <math.h>
#define MAXN 50000
int n[MAXN];
int main(void) {
    int num, start, end;
    int sum = 2, x = 2, i = 0, j = 0, count = 0, maxn = 0;
     
    scanf("%d", &num);
    while (sum <= num) {
        if (num % sum == 0) {
            n[j++] = x++;
            count++;
            sum *= x;
        }
        else {
            n[j++] = x++;
            sum = sum / n[i] * x;
            i++;
        }
        if (count > maxn) {
            maxn = count;
            start = i;
            end = j - 1;
        }
        if (maxn == 0 && sum > sqrt(num)) {			//原来写的是 sum * sum > num  (sum会超出int范围)
            printf("1\n%d\n", num);
            return 0;
        }
    }
    printf("%d\n", maxn);
    for (i = start; i < end; i++)
        printf("%d*", n[i]);
    printf("%d\n", n[end]);
     
    return 0;
}

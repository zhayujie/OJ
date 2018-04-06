#include <stdio.h>
#include <math.h>
int main(void) {
    int n, i;
    int a[1000];
    int sum1 = 0;
    int sum2 = 0, k = 0;
    int count3 = 0;
    double sum4 = 0;
    int count4 = 0;
    int max = 0;
    int count1 = 0, count5 = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        if (a[i] % 10 == 0) {
            sum1 += a[i];
            count1++;
        }
        if (a[i] % 5 == 1) {
            sum2 += a[i] * pow(-1, k);
            k++;
        }
        if (a[i] % 5 == 2)
            count3++;
        if (a[i] % 5 == 3) {
            sum4 += a[i];
            count4++;
        }
        if (a[i] % 5 == 4) {
            count5++;
            if (a[i] > max)
                max = a[i];
        }
    }
    if (count1 > 0)     printf("%d ", sum1);
    else                printf("%c ", 'N');
    if (k > 0)          printf("%d ", sum2);
    else                printf("%c ", 'N');
    if (count3 > 0)     printf("%d ", count3);
    else                printf("%c ", 'N');
    if (count4 > 0)     printf("%.1f ", sum4*1.0/count4);
    else                printf("%c ", 'N');
    if (count5 > 0)     printf("%d\n", max);
    else                printf("%c\n", 'N');
    
    return 0;
}

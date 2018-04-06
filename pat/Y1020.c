#include <stdio.h>
#include <stdlib.h>
int comp(const void * s1, const void * s2);

int main(void) {
    int a[100000];
    int n, i, j, p;
    int max = 0;
    
    scanf("%d%d", &n, &p);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), comp);
    
    for (i = 0; i < n; i++) {
        for (j = i + max; j < n; j++) {
            if (a[i] * p < a[j])
                break;
            max++;
        }
    }

    printf("%d\n", max);
    return 0;
}

int comp(const void * s1, const void * s2) {
    int * p1 = (int *) s1;
    int * p2 = (int *) s2;
    
    return (*p1 - *p2);
}

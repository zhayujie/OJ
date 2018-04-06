#include <stdio.h>
int main(void) {
    int num[10];
    int i, j;
    int k = 0;
    int a[51];
    
    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j < a[i]; j++) {
            a[k++] = i;
        }
    }
    a[k] = 11;
    if (a[0] == 0) {
        for (i = 0; a[i] == 0; i++)
            ;
        a[0] = a[i];
        a[i] = 0;
    }
    
    for (i = 0; a[i] != 11; i++)
        printf("%d", a[i]);
    printf("\n");
    
    return 0;
}

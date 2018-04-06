#include <stdio.h>
int main(void) {
    int a[10];
    char ch[1001];
    int i = 0;
    
    gets(ch);
    
    while (ch[i] != '\0') {
        a[ch[i++] - '0'] += 1;
    }
    
    for (i = 0; i < 10; i++) {
        if (a[i] != 0)
            printf("%d:%d\n", i, a[i]);
    }
       
    return 0;
}

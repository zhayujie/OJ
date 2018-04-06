#include <stdio.h>
int main(void) {
    int n;
    char ch[105][2];
    int i;
    int j = 0, k = 0, l = 0;
    char c1, c2;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%c%c", ch[i][0], ch[i][1]);
        c1 = ch[i][0];
        c2 = ch[i][1];
        if      (c1 == c2)
            k++;
        else if ((c1 == 'J' && c2 =='B') || (c1 == 'B' && c2 == 'C') || (c1 == 'C' && c2 == 'J'))
            j++;
        else
            l++;
    }
    printf("%d %d %d\n", j, k, l);
    printf("%d %d %d\n", l, k, k);

}

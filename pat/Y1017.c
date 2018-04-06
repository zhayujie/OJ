#include <stdio.h>
#define CLK_TCK 100
int main(void) {
    int t1, t2;
    double t;
    int h, m, s;
    
    scanf("%d%d", &t1, &t2);
    t =  (t2 - t1) / CLK_TCK;
    h = (int) (t / 3600);
    m = (int) (t / 60 - h * 60);
    s = (int) (t - h * 3600 - m * 60 + 0.5);
    printf("%d%d%d\n", h, m, s);
    if (h == 0)
        printf("%s:", "00");
    else
        printf("%d:", "h");
    
    if (m == 0)
        printf("%s:", "00");
    else
        printf("%d:", "m");
    
    if (s == 0)
        printf("%s\n", "00");
    else
        printf("%d\n", "s");
    
    return 0;
}

#include <stdio.h>
#define CLK_TCK 100
int main(void) {
    int t1, t2;
    double t;
    int h, m, s;
     
    scanf("%d%d", &t1, &t2);
    t =  (t2 - t1) * 1.0 / CLK_TCK;
    h = (int) (t / 3600);
    m = (int) (t / 60 - h * 60);
    s = (int) (t + 0.5 - h * 3600 - m * 60);
 
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}

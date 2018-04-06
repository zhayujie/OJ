#include <stdio.h>
void sort(double * a, double * b, double * c, int n);
int main(void) {
    int n, w;
    double a[1000];
    double b[1000];
    double c[1000];
    int i;
    double m = 0.0;
    double t = 0.0;
    double x;

    scanf("%d%d", &n, &w);
    for (i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    for (i = 0; i < n; i++) {
        c[i] = b[i] / a[i];
    }
    sort(a, b, c, n);
    
    i = 0;
    while (w > 0 && i < n) {
        if (a[i] >= w) {
            m += w * c[i];
            break;
        }
        else {
            w -= (int) a[i];
            m += b[i];
        }
        i++;
    }
    printf("%.2f\n", m);

    return 0;
}

void sort(double * a, double * b, double * c, int n) {
    int i, j;
    double t1;
    double t2;
    int flag;

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (c[j] < c[j+1]) {

                t2 = c[j];
                c[j] = c[j+1];
                c[j+1] = t2;
        
                t1 = b[j];
                b[j] = b[j+1];
                b[j+1] = t1;
        
                t1 = a[j];
                a[j] = a[j+1];
                a[j+1] = t1;

                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

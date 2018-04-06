#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char a[10000];
    char b[20000];
    int flag1 = 0, flag2 = 0;
    char * s;
    char * s1 = a;
    char * st = b;
    int count = 0;
    int n;
    int m;
    int t = 0;
    int flag3 = 0;
    
    gets(a);
    s = a;
    if (a[0] == '+')
        flag1 = 1;
    s++;
    while (*s++ != 'E') {
        count++;
    }
    if (*s++ == '+')
        flag2 = 1;
    
    n = atoi(s);
    
    if (!flag1)
        *st++ = '-';
    
    s1++;
    if (flag2) {
        
        m = n - (count - 2);
        while (*s1 != 'E') {
            if (t == n+1 && m < 0) {
                *st++ = '.';
            }
            
            if (*s1 == '0' && t < n && !flag3) {
                s1++;
                t++;
                continue;
            }
            if (*s1 == '.') {
                s1++;
                continue;
            }
                
            *st++ = *s1++;
            t++;
            flag3 = 1;
        }
        
        if (m >= 0) {
            while (t != n+1) {
                *st++ = '0';
                t++;
            }
        }
    }
    else {
        if (n == 0) {
            while (*s1 != 'E')
                *st++ = *s1++;
        }
        else {
            *st++ = '0';
            *st++ = '.';
            while (t != n-1) {
                *st++ = '0';
                t++;
            }
            while (*s1 != 'E') {
                if (*s1 == '.') {
                    s1++;
                    continue;
                }
                *st++ = *s1++;
            }
        }
                   
    }
    *st = '\0';
    puts(b);
    
    return 0;
}

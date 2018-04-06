#include <stdio.h>
#include <ctype.h>
int main(void) {
    char s1[80], s2[80], s[80];
    char * p1 = s1;
    char * p2 = s2;
    int i = 0, j = 0;
    int flag;
    
    gets(s1);
    gets(s2);
    while (*p1) {
        if (*p1 == *p2) {
            p1++;
            p2++;
        }
        else {
            flag = 0;
            for (j = 0; j < i; j++) {
                if (s[j] == *p1) {
                    flag = 1;
                    p1++;
                    break;
                }
            }
            if (flag == 0) {
                s[i++] = toupper(*p1++);
            }
        }
    }
    s[i] = '\0';
    puts(s);
    
    return 0;
}

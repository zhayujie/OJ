#include <stdio.h>
#include <ctype.h>
#define SIZE 60
int main(void) {
    char * s[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char st[4][SIZE];
    char *s1, *s2, *s3, *s4;
    int i;
    
    for (i = 0; i < 4; i++)
        gets(st[i]);
    s1 = st[0];
    s2 = st[1];
    s3 = st[2];
    s4 = st[3];
    
    while (*s1 != *s2 || (*s1 < 'A' || *s1 > 'G')) {
        s1++;
        s2++;
    }
    printf("%s ", s[*s1 - 'A']);
    
    s1++;
    s2++;
    while (*s1 != *s2 || ((*s1 < '0' || *s1 > '9') && (*s1 < 'A' || *s1 > 'N'))) {
        s1++;
        s2++;
    }

    if (*s1 >= '0' && *s1 <= '9')
        printf("0%c:", *s1);
    else
        printf("%d:", *s1-'A'+10);

    i = 0;
    while (*s3 != *s4 || ((*s3 < 'a' || *s3 > 'z') && (*s3 < 'A' || *s3 > 'Z'))) {
        s3++;
        s4++;
        i++;
    }
    if (i < 10)
        printf("0%d\n", i);
    else
        printf("%d\n", i);
}

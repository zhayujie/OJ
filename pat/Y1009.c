#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp1(const void * s1, const void * s2);
int comp2(const void * s1, const void * s2);
void myitoa(int val, char * st);
void copy(char * st1, char * st2);
int myatoi(char * st);


int main(void) {
    char st[5];
    char st1[5], st2[5];
    int res;
    int i = 0;
    
    gets(st);
    while (st[i])
        i++;
    while (i < 4)
        st[i++] = '0';
    st[i] = '\0';

    while (1) {
        if (st[0] == st[1] && st[1] == st[2] && st[2] == st[3]) {
            printf("%s - %s = 0000\n", st, st);
            return 0;
        }
    
        copy(st, st1);
        copy(st, st2);
    
        qsort(st1, 4, sizeof(char), comp2);
        qsort(st2, 4, sizeof(char), comp1);
        res = myatoi(st1) - myatoi(st2);
        myitoa(res, st);
        printf("%s - %s = %s\n", st1, st2,st);
        if (strcmp(st, "6174") == 0)
            break;
    }
    return 0;
}

void copy(char * st1, char * st2) {
    while (*st1)
        *st2++ = *st1++;
    *st2 = '\0';
}
int comp1(const void * s1, const void * s2) {
    char * st1 = (char *) s1;
    char * st2 = (char *) s2;
    if (*st1 > *st2)
        return 1;
    else if (*st1 == *st2)
        return 0;
    else return -1;
}

int comp2(const void * s1, const void * s2) {
    char * st1 = (char *) s1;
    char * st2 = (char *) s2;
    if (*st1 < *st2)
        return 1;
    else if (*st1 == *st2)
        return 0;
    else return -1;
}

void myitoa(int val, char * st) {
    int i;
    for (i = 3; i >= 0; i--) {
        st[i] = val % 10 + '0';
        val /= 10;
    }
}

int myatoi(char * st) {
    int sum = 0;
    while (*st)
        sum = 10 * sum + (*st++ - '0');
    return sum;
}

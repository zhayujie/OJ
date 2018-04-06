#include <stdio.h>
#include <string.h>
int main(void) {
    int n, i;
    char * most = "1814/09/06"
    char * today = "2014/09/06";
    char name[100000][6];
    char age[100000][11];
    char s1[6], s2[11];
    int count = 0;
    char h[6], l[6];
    char ha[11], hl[11];
  
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s%s", s1, s2);
        if (strcmp(s2, most) < 0 || strcmp(s2, today) > 0) {
            strcpy(name[count++], s1);
            strcpy(age[count++], s2);
        }
    }
    strcpy(h, name[0]);
    strcpy(ha, age[0]);
    strcpy(l, name[0]);
    strcpy(la, age[0]);
    for (i = 0; i < count; i++) {
        if (strcmp(age[i], ha) < 0) {
            strcpy(h, name[i]);
            strcpy(ha, age[i]);
        }
        else if (strcmp(age[i], la) > 0) {
            strcpy(l, name[i]);
            strcpy(la, age[i]);
        }
    }
    printf("%d %s %s\n", count, h, l);
    
    return 0;
}

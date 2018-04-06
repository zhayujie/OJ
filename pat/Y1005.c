#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000
//int comp(const void * s1, const void * s2);

typedef struct student {
    char id[9];
    int x;
    int y;
    int z;
} stud, stu[SIZE];

int comp(stud s1, stud s2);
void sort(stud * p, int n);
stu b, c, d, e;				//结构体数组需要存储在静态区，不然会溢出

int main(void) {
    stud s;
    int n, l, h, i;
    int j = 0, k = 0, t = 0, m = 0, count = 0;
    
    scanf("%d%d%d", &n, &l, &h);
    for (i = 0; i < n; i++) {
        scanf("%s%d%d", s.id, &s.x, &s.y);
        s.z = s.x + s.y;

        if (s.x < l || s.y < l)
            continue;
        else if (s.x >= h && s.y >= h)
            b[j++] = s;
        else if (s.x >= h && s.y < h)
            c[k++] = s;
        else if (s.x < h && s.y <h && s.x >= s.y)
            d[t++] = s;
        else
            e[m++] = s;
        count++;
    }
    sort(b, j);
    sort(c, k);
    sort(d, t);
    sort(e, m);
    
    printf("%d\n", count);
    for (i = 0; i < j; i++) {
        printf("%s %d %d\n", b[i].id, b[i].x, b[i].y);
    }
    for (i = 0; i < k; i++) {
        printf("%s %d %d\n", c[i].id, c[i].x, c[i].y);
    }
    for (i = 0; i < t; i++) {
        printf("%s %d %d\n", d[i].id, d[i].x, d[i].y);
    }
    for (i = 0; i < m; i++) {
        printf("%s %d %d\n", e[i].id, e[i].x, e[i].y);
    }
    
    return 0;
}

//冒泡排序
void sort(stud * p, int n) {
    int i, j;
    stud temp;
    int flag;

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < n-1-i; j++) {
            if (comp(p[j], p[j+1]) < 0) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)	return;
    }
    return;
}

int comp(stud s1, stud s2) {
    if (s1.z < s2.z)
        return -1;
    else if (s1.z > s2.z)
        return 1;
    else if (s1.x > s2.x)
        return 1;
    else if (s1.x < s2.x)
        return -1;
    else if (strcmp(s1.id, s2.id) < 0)
        return 1;
    else
        return -1;
}

/*
int comp(const void * s1, const void * s2) {
    stu * stu1 = (stu *) s1;
    stu * stu2 = (stu *) s2;
    if (stu1->z > stu2->z)
        return -1;
    else if (stu1->z == stu2->z)
        return 0;
    else
        return 1;
}
*/

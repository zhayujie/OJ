#include <cstdio>
#include <string.h>
void print_str(char * s, int n, int count);
int main(void) {
    int n, i;
    char s1[105], s2[105], res1[105], res2[105];
    
    scanf("%d %s %s", &n, s1, s2);
    int count1 = strlen(s1), count2 = strlen(s2);       //小数点位置
    int p = 0, q = 0;                                   //第一个有效数字的位置
    
    //分别计算两个数的 小数点位置，首个有效数位置，幂指数
    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] == '.') {
            count1 = i;
            break;
        }
    }
    for (i = 0; i < strlen(s2); i++) {
        if (s2[i] == '.') {
            count2 = i;
            break;
        }
    }
    while (s1[p] == '0' || s1[p] == '.')    p++;
    while (s2[q] == '0' || s2[q] == '.')    q++;
    int k1 = count1 - p;                                //k1, k2 表示指数
    if (k1 < 0)             k1++;
    int k2 = count2 - q;
    if (k2 < 0)             k2++;
    if (p == strlen(s1))    k1 = 0;                     //0.000.. 的情况
    if (q == strlen(s2))    k2 = 0;
    
    //将两字符串的n位 底数部分 复制到结果数组
    int index1 = 0, index2 = 0;
    while (index1 < n) {
        if (p < strlen(s1) && s1[p] != '.')
            res1[index1++] =  s1[p];
        else if (p >= strlen(s1))
            res1[index1++] = '0';
        p++;
    }
    res1[index1] = '\0';
    while (index2 < n) {
        if (q < strlen(s2) && s2[q] != '.')
            res2[index2++] =  s2[q];
        else if (q >= strlen(s2))
            res2[index2++] = '0';
        q++;
    }
    res2[index2] = '\0';
    if (!strcmp(res1, res2) && k1 == k2)
        printf("YES 0.%s*10^%d\n", res1, k1);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", res1, k1, res2, k2);
        
    return 0;
}

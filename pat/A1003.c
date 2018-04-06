#include <stdio.h>
#include <math.h>
int main(void) {
    int n, i, x;
    int max = 0, mcount = 0;	//max是最大间隔数，mcount是同样价格最高的商店数量
    double p, r;
    //id数组储存该商店的上一级的索引，count数组储存从该商店到根供应商需要几次提价
    static int id[100000], count[100000];
    
    scanf("%d%lf%lf", &n, &p, &r);
    for (i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }
    for (i = 0; i < n; i++) {
        x = i;
    /*	if (count[i] < 0)
            continue;  */
        while (id[x] != -1) {
            x = id[x];
            count[i]++;
            if (count[x] > 0) {
                count[i] += count[x];
                break;
            }
    /*		count[x] = -1;    */
        }
        if (count[i] > max) {
            max = count[i];
            mcount = 1;
        }
        else if (count[i] == max) {
            mcount++;
        }
    }
    printf("%.2f %d\n", p*pow(r/100+1, max), mcount);
    
    return 0;
}


/*
#include <stdio.h>
#include <math.h>
int main(void) {
    int n, i, x;
    int max = 0, mcount = 0, count;	//max是最大间隔数，mcount是同样价格最高的商店数量
    double p, r;
    //id数组储存该商店的上一级的索引，count数组储存从该商店到根供应商需要几次提价(用空间换时间)
    static int id[100000];
    
    scanf("%d%lf%lf", &n, &p, &r);
    for (i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }
    for (i = 0; i < n; i++) {
        x = i;
        count = 0;
        while (id[x] != -1) {
            x = id[x];
            count++;
        }
        if (count > max) {
            max = count;
            mcount = 1;
        }
        else if (count == max) {
            mcount++;
        }
    }
    printf("%.2f %d\n", p*pow(r/100+1, max), mcount);
    
    return 0;
}
*/

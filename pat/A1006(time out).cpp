#include <cstdio>
#include <string.h>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#define MAXN 10000
#define MAXK 80000
typedef struct {
    char number[8];
    int time;
    int state;
} Car;
typedef struct {
    int t1;
    int t2;
    int flag;
} Pair;
Car car[MAXN];
Pair p[MAXN];
Pair pa[MAXN][1000];
int interval[MAXN];
int pair_count[MAXN];
int t_query[MAXK];
char str[MAXN][8];
int n_query[MAXK];
bool comp(Car a, Car b);

using namespace std;

int main(void) {
    int n, k, i, j, v, h, m, s, pf, cs, index, tq;
    char plate_num[8], st[5];
    map<string, int> num;
    map<string, int>::iterator iter;
    int cnt = 0, max = 0;
    string pn;
    
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", plate_num, &h, &m, &s, &st);
        if (!num.count(plate_num)) {
            strcpy(str[cnt], plate_num);
            num.insert(pair<string, int>(plate_num, cnt++));
        }

        strcpy(car[i].number, plate_num);
        car[i].time = h * 3600 + m * 60 + s;
        if (strlen(st) == 2)
            car[i].state = 1;
        else
            car[i].state = 0;				 //in:1  out:0
    }
    for (i = 0; i < k; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        t_query[i] = h * 3600 + m * 60 + s;
    }
    sort(car, car+n, comp);
    for (i = 0; i < n; i++) {
        pn = car[i].number;		//注意这里map的find()方法键类型是string而不是char[]
        iter = num.find(pn);
        index = iter->second;
        pf = p[index].flag;
        cs = car[i].state;

        if (pf == 0 && cs == 1) {
            p[index].t1 = car[i].time;
            p[index].flag = 1;		//错误：pf = 1;
        }
        else if (pf == 1 && cs == 0) {
            p[index].t2 = car[i].time;
            p[index].flag = 0;		//开始写的是pf = 0; 重大失误
            pa[index][pair_count[index]++] = p[index];
            interval[index] += p[index].t2 - p[index].t1;
        }
        else if (pf == 1 && cs == 1) {
            p[index].t1 = car[i].time;
        }
    }
    
    for (i = 0; i < k; i++) {
        tq = t_query[i];
        for (j = 0; j < cnt; j++) {
            if (tq < pa[j][0].t1 || tq >= pa[j][pair_count[j]-1].t2)
                continue;
            for (v = 0; v < pair_count[j]; v++) {
                if (tq < pa[j][v].t2) {
                    if (tq >= pa[j][v].t1)
                       n_query[i]++;
                    else
                        break;
               }
            }
        }
    }
    for (i = 0; i < k; i++)
        printf("%d\n", n_query[i]);
    for (i = 0; i < cnt; i++)
        if (interval[i] > max)
            max = interval[i];
    for (i = 0; i < cnt; i++)
        if (interval[i] == max)
            printf("%s ", str[i]);
    printf("%02d:%02d:%02d\n", max / 3600, max % 3600 / 60, max % 3600 % 60);

    return 0;
}

bool comp(Car a, Car b) {
    return a.time < b.time;
}

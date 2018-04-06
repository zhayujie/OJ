#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#define MAXN 10010
#define MAXK 80010
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
int k;
int q_rank(int key, int a[]);

using namespace std;
bool comp(Car a, Car b);
string num_max[MAXN];

int main(void) {
    int n, i, j, v, h, m, s, pf, cs, index, tq;
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
        pn = car[i].number;			//注意这里map的find()方法键类型是string而不是char[]
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

    int x, y;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < pair_count[i]; j++) {
            x = pa[i][j].t1;
            y = pa[i][j].t2;
            if (y <= t_query[0] || x > t_query[k-1])    continue;
            int r1 = q_rank(x, t_query);
            int r2 = q_rank(y, t_query);
            for (int w = r1 + 1; w <= r2; w++)
                n_query[w]++;
            //边界调节 如果在查找时刻in则该时刻车数+1, 如果在该时刻out则不计入车数
            if (x >= 0 && x == t_query[r1])	//注意这里如果 x < t_query[0] 那么 r1 = -1 出现越界
                n_query[r1]++;
            if (y == t_query[r2])
                n_query[r2]--;
    //		printf("%s   %d   %d    %d %d\n", str[i], x, y, r1, r2);
        }
    }
    for (i = 0; i < k; i++)
        printf("%d\n", n_query[i]);
    //停留时间最长的车牌号按字典序输出
    j = 0;
    for (i = 0; i < cnt; i++)
        if (interval[i] > max)
            max = interval[i];
    for (i = 0; i < cnt; i++)
        if (interval[i] == max)
            num_max[j++] = str[i];
    sort(num_max, num_max+j);
    for (i = 0; i < j; i++)
        cout<<num_max[i]<<" ";
    printf("%02d:%02d:%02d\n", max / 3600, max % 3600 / 60, max % 60);

    return 0;
}

bool comp(Car a, Car b) {
    return a.time < b.time;
}

int q_rank(int key, int a[]) {
    int i = 0, j =  k - 1;
    
    while (i <= j) {
        int mid = (i + j) / 2;
        if (key < a[mid])
           j = mid - 1;
        else if (key > a[mid])
           i = mid + 1;
        else
            return mid;
    }
    return j;
}

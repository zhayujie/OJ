#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#define MAXN 10000
#define MAXT 24*3600
using namespace std;
struct Car {
    char id[8];
    int time;
    bool in;
} car[MAXN];
int t[MAXT];
map<string, int> sumtime;
bool comp(Car a, Car b);

int main(void) {
    int n, k, h, m, s, i;
    
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        char status[5];
        scanf("%s %d:%d:%d %s", car[i].id, &h, &m, &s, status);
        car[i].time = h * 3600 + m * 60 + s;
        car[i].in = (strcmp(status, "in") == 0);
    }
    sort(car, car+n, comp);
    int maxtime = 0;
    for (i = 0; i < n-1; i++) {
        if (!strcmp(car[i].id, car[i+1].id)) {
            if (car[i].in && !car[i+1].in){
                sumtime[car[i].id] += (car[i+1].time - car[i].time);
                t[car[i].time]++;
                t[car[i+1].time]--;
            }
        }
        maxtime = max(maxtime, sumtime[car[i].id]);
    }
    for (i = 1; i < MAXT; i++)
        t[i] += t[i-1];
    for (i = 0; i < k; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        int t_query = h * 3600 + m * 60 + s;
        printf("%d\n", t[t_query]);
    }
    map<string, int>::iterator iter;
    for (iter =sumtime.begin(); iter != sumtime.end(); iter++) {
        if (iter->second == maxtime)
            cout<<iter->first<<" ";
    }
    printf("%02d:%02d:%02d\n", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
    
    return 0;
}
bool comp(Car a, Car b) {
    if (strcmp(a.id, b.id))     return strcmp(a.id, b.id) < 0;
    else                        return a.time < b.time;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    2.一共M个数字(偶数)， 两两组合，使得 每一对数字和最大的那个值 最小
    给出M个数字的 频度 和 值， 如：
    2 1
    3 5
    序列为 1 1 5 5 5
*/

typedef struct worker {
    int time;
    int num;
} worker;
vector<worker> vec;

bool cmp(worker w1, worker w2) {
    return w1.time < w2.time;
}

int main(void) {
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, t;
        cin >> x >> t;
        worker w;
        w.num = x;
        w.time = t;
        vec.push_back(w);
    }
    sort(vec.begin(), vec.end(), cmp);
    int maxCount = 0; 
    int i = 0, j = vec.size()-1;
    while (i <= j) {
        int count = vec[i].time + vec[j].time;
        maxCount = max(count, maxCount);
        vec[i].num -= 1;
        vec[j].num -= 1;
        if (vec[i].num <= 0)   i++;
        if (vec[j].num <= 0)   j--;
        // cout << "i: " << i << " j: " << j << endl;
    }
    cout << maxCount << endl;

    return 0;
}
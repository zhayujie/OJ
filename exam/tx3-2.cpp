#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printPower(vector<int> &vec) {
    sort(vec.begin(), vec.end());
    return;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        vector<int> vec;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
            vec.push_back(p);
        }
        printPower(vec);
    }
    return 0;
}
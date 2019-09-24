#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int n;
    
    cin >> n;
    priority_queue<long> pq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        long temp;
        cin >> temp;
        pq.push(temp);
    }
    
    while (true) {
        long max = pq.top();
        // cout << "max: " << max+count << endl;
        if (max + count < n) {
            break;
        }
        pq.pop();
        pq.push(max-n-1);
        count++;
    }
    for (int i = 0; i < n; i++) {
        cout << pq.top()+count << endl;
        pq.pop();
    }

    cout << "count: " << count << endl;

    return 0;
}
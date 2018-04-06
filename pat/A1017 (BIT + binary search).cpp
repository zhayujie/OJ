#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#define MAXN 100005
using namespace std;
int stack[MAXN];            //array of stack
int c[MAXN];                //BIT
int n = 0;
/*
    functions of Binary Index Tree (BIT)
    */
int lowbit(int x) {
    return x & (-x);
}
int get_sum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void update(int x, int t) {
    for (int i = x; i <= MAXN; i += lowbit(i))
        c[i] += t;
}

/*
    operations of stack
    */
bool isEmpty() {
    return n == 0;
}
void push(int key) {
    stack[n++] = key;
    update(key, 1);
}
int pop() {
    int k = stack[--n];
    update(k, -1);
    return k;
}
int peek_median() {
    int lo = 1, hi = MAXN;
    int median = (n + 1) / 2;
    
    //use the binary search
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (median > get_sum(mid))
            lo = mid + 1;
        else								// median <= get_sum(mid)
            hi = mid - 1;
    }
    return lo;
}


int main(void) {
    int m;
    char comment[11];
    
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++) {
        gets(comment);
        if (comment[1] == 'u') {			//push
            int key = atoi(comment+5);
            push(key);
        }
        else if (comment[1] == 'o') {		//pop
            if(isEmpty()) {
                printf("Invalid\n");
                continue;
            }
            int t = pop();
            printf("%d\n", t);
        }
        else {								//peek median
            if (isEmpty()) {
                printf("Invalid\n");
                continue;
            }
            int m = peek_median();
            printf("%d\n", m);
        }
    }
    
    return 0;
}

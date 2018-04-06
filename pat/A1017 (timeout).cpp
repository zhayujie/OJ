#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#define MAXN 100005
using namespace std;
int stack[MAXN];
int count[MAXN];
int n = 0;
bool isEmpty() {
    return n == 0;
}

void push(int key) {
    stack[n++] = key;
    count[key]++;
}

int pop() {
    int k = stack[--n];
    count[k]--;
    return k;
}

int peek_median() {
    int sum = 0, i = 0;
    int m = (n + 1) / 2;
    
    while (sum < m) {
        sum += count[i];
        i++;
    }
    
    return i-1;
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

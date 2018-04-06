#pragma warning(disable:4786)
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
typedef struct lnode{
    int address;
    int val;
    int next;
} Node;

Node node[100000];
int count[10000];

int main(void) {
    int start, n;
    vector<Node> vec;
    vector<Node>::iterator iter;
    
    cin>>start>>n;
    for (int j = 0; j < n; j++) {
        int index;
        cin >> index;
        cin >> node[index].val >> node[index].next;
        node[index].address = index;
    }
    
    printf("%05d %d ", start, node[start].val);			//the address and value of the first node
    count[abs(node[start].val)]++;
    for (int i = node[start].next; i != -1; i = node[i].next) {
        int k = abs(node[i].val);
        if (count[k] == 0) {
            printf("%05d\n%05d %d ", i, i, node[i].val);
            count[k]++;
        }
        else {
            vec.push_back(node[i]);
        }
    }
    printf("-1\n");
    printf("%05d %d ", vec[0].address, vec[0].val);		//the address and value of the first removed node
    for (iter = vec.begin()+1; iter != vec.end(); iter++) {
        printf("%05d\n%05d %d ", (*iter).address, (*iter).address, (*iter).val);
    }
    printf("-1\n");
    
    return 0;
}

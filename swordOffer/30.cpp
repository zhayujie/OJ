#include <iostream>
using namespace std;
#include <stack>

class Solution {
public:
    int minVal = INT32_MAX;
    stack<int> valStack;
    stack<int> minStack;
    
    void push(int value) {
        valStack.push(value);
        minStack.push(minVal);   // 记录旧的最小值
        if (value < minVal) {
            minVal = value;
        }
    }
    void pop() {
        valStack.pop();
        minVal = minStack.top();
        minStack.pop();
    }
    int top() {
        return valStack.top();
    }
    int min() {
        return minVal;
    }
};
int main(void) {
    Solution soulution;
    return 0;
}

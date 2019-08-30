#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
      if (!stack2.size()) {
        while (stack1.size()) {
          int v1 = stack1.top();
          stack2.push(v1);
          stack1.pop();
        }
      }
      int val = stack2.top();
      stack2.pop();
      return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(void) {
  Solution soulution;


  return 0;
}

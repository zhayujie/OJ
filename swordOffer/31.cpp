#include <iostream>
using namespace std;
#include <vector>
#include <stack> 

class Solution {
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
      int size = pushV.size();
      stack<int> stack;
      int i = 0, j = 0;
      while (j < size) {
        if (i < size) {
          stack.push(pushV[i++]);
        }
        if (stack.top() == popV[j]) {
          stack.pop();
          j++;
        } else if (i == size) {
          // 出栈序列不等于栈顶元素，且入栈已经完成，此时直接宣布不匹配
          return false;
        }
      }
      return true;
    }
};

int main(void) {

}
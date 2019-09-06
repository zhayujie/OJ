#include <iostream>
#include <vector>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
((ur)oi)
******************************开始写代码******************************/
string resolve(string expr) {
  vector<char> stack;
  int flag = 0;
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] != ')') {
      stack.push_back(expr[i]);
    } else {
      string st = "";
      while (stack.size() > 0) {
        char top = stack[stack.size()-1];
        if (top != '(') {
          st += top;
          stack.pop_back();
        } else {
          stack.pop_back();
          for (int j = 0; j < st.length(); j++) {
            stack.push_back(st[j]);
          }
          break;
        }
      }
    }
  }
  string st = "";
  for (int i = 0; i < stack.size(); i++) {
    if (stack[i] == '(')    return "";
    st += stack[i];
  }
  return st;
}

/******************************结束写代码******************************/


int main() {
    string res;

    string _expr;
    getline(cin, _expr);
    
    res = resolve(_expr);
    cout << res << endl;
    
    return 0;

}

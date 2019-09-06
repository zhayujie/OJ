#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
struct TreeNode {
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(char x) :
		val(x), left(NULL), right(NULL) {
	}
};

void printTree(TreeNode* head, string &st) {
  if (head == NULL) return;
  printTree(head->left, st);
  st += head->val;
  printTree(head->right, st);
}

int findTree(string tree, int i, int j) {
  if (i+2 < tree.length() && tree[i+2] == ',') {
    return i+2;
  }
  if (i+3 < tree.length() && tree[i+3] == ',') {
    return i+3;
  }
  int count = 0;
  for (int k = i+2; k <= j-1; k++) {
    if (tree[k] == '(') {
      count++;
    }
    if (tree[k] == ')') {
      count--;
      if (count == 0) {
        return k+1;
      }
    }
  }
  return i+1;
}

TreeNode* createTree(string tree, int i, int j) {
  if (i > j) return NULL; 
  TreeNode* head = new TreeNode(tree[i]);
  if (i == j) return head;
  int index = findTree(tree, i, j);
  cout << "i: " << i << " j: " << j << " index:" << index << endl;

  head->left = createTree(tree, i+2, index-1);
  head->right = createTree(tree, index+1, j-1);
  return head;
}

string solution(string input) {
  if (input.length() == 1)    return input;
  TreeNode* head = createTree(input, 0, input.length()-1);
  string st = "";
  printTree(head, st);
  return st;
}


/******************************结束写代码******************************/


int main() {
    string res;

    string _input;
    getline(cin, _input);
    
    res = solution(_input);
    cout << res << endl;
    
    return 0;

}

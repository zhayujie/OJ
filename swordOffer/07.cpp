#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
      return constructTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }

    TreeNode* constructTree(vector<int> pre, int preBeg, int preEnd, vector<int> vin, int vinBeg, int vinEnd) {
      if (preEnd - preBeg < 0)   return NULL;
      TreeNode *node = new TreeNode(pre[preBeg]);
      for (int i = vinBeg; i <= vinEnd; i++) {
        if (pre[preBeg] == vin[i]) {
          node->left = constructTree(pre, preBeg+1, preBeg+i-vinBeg, vin, vinBeg, i-1);
          node->right = constructTree(pre, preBeg+i-vinBeg+1, preEnd, vin, i+1, vinEnd);
        }
      }

      return node;
    }
};

int main(void) {
  Solution soulution;

  TreeNode root(3);

  return 0;
}

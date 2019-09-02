#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
      bool res = false;
      if (pRoot1 == NULL || pRoot2 == NULL)   return false;
      if (pRoot1->val == pRoot2->val) {
        res = hasSubtreeCore(pRoot1, pRoot2);
      }
      if (!res) {
        res = HasSubtree(pRoot1->left, pRoot2);
      }
      if (!res) {
        res = HasSubtree(pRoot1->right, pRoot2);
      }
      return res;
    }

    bool hasSubtreeCore(TreeNode* pRoot1, TreeNode* pRoot2) {
      if (pRoot2 == NULL)   return true;
      if (pRoot1 == NULL)   return false;
      if (pRoot1->val != pRoot2->val)   return false;
      return hasSubtreeCore(pRoot1->left, pRoot2->left) && hasSubtreeCore(pRoot1->right, pRoot2->right);
    }
};

int main(void) {
  Solution soulution;
  return 0;
}

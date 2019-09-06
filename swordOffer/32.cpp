#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector<int> vec;
      queue<TreeNode*> queue;
      if (root == NULL)   return vec;
      queue.push(root);
      while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        vec.push_back(node->val);
        if (node->left != NULL)       queue.push(node->left);
        if (node->right != NULL)      queue.push(node->right);
      }
      return vec;
    }
};

int main(void) {

}
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

bool cmp(vector<int> v1, vector<int> v2) {
	return v1.size() > v2.size();
}

class Solution {
vector<vector<int> > res;
public:
		void FindPathCore(TreeNode* root, int expectNumber, vector<int> &path, int count) {
			if (root == NULL) 	return;
			int val = root->val;
			path.push_back(val);			
			if (root->left == NULL && root->right == NULL) {
				if (count + val == expectNumber) {
					res.push_back(path);			// 会调用拷贝构造函数
				}
			} else {
				FindPathCore(root->left, expectNumber, path, count + val);
				FindPathCore(root->right, expectNumber, path, count + val);
			}
			path.pop_back();							// 如果传vector地址，则这里需要弹出
			return;
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
			vector<int> path;
			FindPathCore(root, expectNumber, path, 0);
			sort(res.begin(), res.end(), cmp);
			return res;
    }
};

int main(void) {

}

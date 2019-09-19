#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) {
            return false;
        }
        // 判断当前序列是否满足后序遍历
        int i = 0;
        int size = sequence.size();
        int root = sequence[size-1];
        while (i < size-1) {
            if (sequence[i] > root) {
                break;
            }
            i++;
        }
        int j = i;
        while (j < size-1) {
            if (sequence[j] < root) {
                return false;
            }
            j++;
        }
        // 判断左子树是否是后序遍历
        bool left = true, right = true;
        if (i > 0) {
            vector<int> leftSeq(sequence.begin(), sequence.begin()+i);
            bool left = VerifySquenceOfBST(leftSeq);
        }
        // 判断右子树是否是后序遍历
        if (j > i) {
            vector<int> rightSeq(sequence.begin()+i, sequence.end()-1);
            bool right = VerifySquenceOfBST(rightSeq);
        }
        return (left && right);
    }
};

int main(void) {
    Solution solution;
    int test[] = {5, 7, 6, 9, 11, 10, 8};
    vector<int> vec(test, test+7);
    bool res = solution.VerifySquenceOfBST(vec);
    cout << res << endl;
}

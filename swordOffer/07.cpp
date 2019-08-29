#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
    val(x), next(NULL) {
  }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> vec;

      while (head != NULL) {
        vec.push_back(head->val);
        head = head->next;
      }
      reverse(vec.begin(), vec.end());
      return vec;
    }
};

int main(void) {
  Solution soulution;

  ListNode head(6);

  soulution.printListFromTailToHead(&head);

  return 0;
}

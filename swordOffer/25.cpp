#include <iostream>
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* pHead3 = NULL;
        ListNode* cur = NULL;
        while (pHead1 || pHead2) {
          if (!pHead2 || (pHead1 && (pHead1->val <= pHead2->val))) {
            if (!cur) {
              cur = pHead1;
            } else {
              cur->next = pHead1;
              cur = cur->next;
            }
            pHead1 = pHead1->next;
          } else if (!pHead1 || (pHead1->val > pHead2->val)) {
            if (!cur) {
              cur = pHead2;
            } else {
              cur->next = pHead2;
              cur = cur->next;
            }
            pHead2 = pHead2->next;
          }
          cur->next = NULL;
          if (!pHead3)    pHead3 = cur;
        }
        return pHead3;
    }
};


int main(void) {
  Solution soulution;
  return 0;
}

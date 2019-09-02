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
  ListNode* ReverseList(ListNode* pHead) {
    if (pHead == NULL || pHead->next == NULL) {
      return pHead;
    }
    ListNode* newHead = ReverseList(pHead->next);
    pHead->next->next = pHead;
    pHead->next = NULL;
    return newHead;
  }
};

int main(void) {
  Solution soulution;
  return 0;
}

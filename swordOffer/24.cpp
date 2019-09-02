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
      ListNode *pre = NULL;
      while (pHead != NULL) {
        ListNode *next = pHead->next;
        pHead->next = pre;      
        pre = pHead;
        pHead = next;
      }
      return pre;
    }
};

int main(void) {
  Solution soulution;
  return 0;
}

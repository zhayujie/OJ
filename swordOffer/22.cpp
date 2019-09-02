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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if (k == 0)   return NULL;
      ListNode* prev = pListHead;
      int count = 0;
      while (pListHead != NULL) {
        count++;
        if (count > k) {
          prev = prev->next;
        }
        pListHead = pListHead->next;
      }
      if (count < k) {
        return NULL;
      } else {
        return prev;
      }
    }
};

int main(void) {
  Solution soulution;
  return 0;
}
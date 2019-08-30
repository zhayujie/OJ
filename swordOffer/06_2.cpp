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
    vector<int> vec;
    vector<int> printListFromTailToHead(ListNode* head) {
      if (head == NULL)   return vec;
      if (head->next != NULL) {
        printListFromTailToHead(head->next);
      }
      vec.push_back(head->val);
      return vec;
    }
};

int main(void) {
  Solution soulution;

  ListNode head(6);

  soulution.printListFromTailToHead(&head);

  return 0;
}

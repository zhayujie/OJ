#include <iostream>
using namespace std;
#include <map>
#include <algorithm>


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if (pHead == NULL)	return pHead;
		map<RandomListNode*, RandomListNode*> listMap;
        RandomListNode* copyHead = new RandomListNode(pHead->label);
		RandomListNode* newHead = copyHead;
		RandomListNode* originHead = pHead;
		pair<RandomListNode*, RandomListNode*> val(originHead, newHead);
		listMap.insert(val);
		while (originHead != NULL && originHead->next != NULL) {
			originHead = originHead->next;
			newHead->next = new RandomListNode(originHead->label);
			newHead = newHead->next;
			pair<RandomListNode*, RandomListNode*> val(originHead, newHead);
			listMap.insert(val);
		}
		originHead = pHead;
		while (originHead != NULL) {
			listMap[originHead]->random = listMap[originHead->random];
			originHead = originHead->next;
		}
		return copyHead;
    }
};

int main(void) {
	Solution solution;
	RandomListNode* rln = new RandomListNode(1);
	rln->next = new RandomListNode(2);
	rln->next->next = new RandomListNode(3);
	
	RandomListNode* res = solution.Clone(rln);
	cout << res->label << res->next->label << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    };
};

/*请完成下面这个函数，实现题目要求的功能
******************************开始写代码******************************/
ListNode* partition(ListNode* head,int m) {
  if (head == NULL)   return NULL;
  ListNode * oldHead = head;
  ListNode * minHead = head;
  ListNode * minPre = head;
  ListNode * headPre = head;

  while (head != NULL) {
    if (head->val > m) {
      minHead = head;
      break;
    }
    minPre = head;
    head = head->next;
  }
  while (head != NULL) {
    if (head->val <= m) {
      ListNode * temp = head->next;
      headPre->next = temp;

      head->next = minHead;
      if (minPre != minHead) {
        minPre->next = head;
      } else {
        oldHead = head;
      }
      minPre = head;
      head = temp;
      continue;
    }
    headPre = head;
    head = head->next;
  }

  return oldHead;
}
/******************************结束写代码******************************/


int main() {
    ListNode* head=NULL;
    ListNode* node=NULL;
    int m;
    cin>>m;
    int v;
    while(cin>>v){
        if(head==NULL){
            node=new ListNode(v);
            head=node;
        }else{
            node->next=new ListNode(v);
            node=node->next;
        }
    }
    head = partition(head,m);
    if(head!=NULL){
        cout<<head->val;
        node=head->next;
        delete head;
        head=node;
        while(head!=NULL){
            cout<<","<<head->val;
            node=head->next;
            delete head;
            head=node;
        }
    }
    cout<<endl;
    return 0;
}

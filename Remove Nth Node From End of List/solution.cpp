/**
 * Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.**/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
	//当fast==null时，倒数第n个，那么就是和fast距离n的指针啊。所以这里
	//进行--啊。
    ListNode *fast = head, **cur = &head;
	//哎，使用两个while循环比较简单明了啊。
    while(n--) fast = fast->next;
    while (fast) {
        fast = fast->next;
        cur = &(*cur)->next;  }
    *cur = (*cur)->next;
    return head;
	}
};
int main() {
	ListNode node(1);
	ListNode node2(2);
	node.next=&node2;
	Solution solution;
	solution.removeNthFromEnd(&node,1);


}

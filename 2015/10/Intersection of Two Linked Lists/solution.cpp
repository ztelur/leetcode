/**
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 解法 加入二者是相交的，那么，长的那一条先遍历过开头长的位置，然后二者比较，找出第一个相同的地方
 *
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   		int lengthA = 0,lengthB = 0;
		ListNode* iterA = headA,iterB = headB;
		while (iterA != NULL) {
			lengthA++;
			iterA = iterA->next;
		}
		while (iterB != NULL) {
			lengthB++;
			iterB = iterB->next;
		}
		iterA = headA,iterB = headB;

		if (lengthA > lengthB ) {
			while (lengthA != lengthB) {
				iterA = iterA->next;
				lengthA--;
			}
		} else {
			while (lengthB != lengthA) {
				iterB = iterB->next;
				lengthB--;
			}
		}
		
		while (iterA != NULL && iterB != NULL) {
			if (iterA == iterB) {
				return iterA;
			}
			iterA = iterA->next;
			iterB = iterB->next;
		}
		return NULL;
    }
};

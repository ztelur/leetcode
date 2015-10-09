/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Given a linked list,determine if it has a cycle in it
 * can you solve it without using extra space
 *
 * 明白为什么使用两个指针啊，快慢指针如果有环就一定会相遇的啊！！！
 * 10.9 21:37 two points 
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
		ListNode* slow = head;
		while(fast!=NULL && fast->next!=NULL) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
    }
};

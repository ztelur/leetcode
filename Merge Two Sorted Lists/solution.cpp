/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * res=new ListNode(1);
        ListNode * itr=res;
        while(l1!=NULL&&l2!=NULL) {
        	if (l1->val<l2->val) {
        		itr->next=l1;
        		itr=itr->next;
        		l1=l1->next;
        	} else {
        		itr->next=l2;
        		itr=itr->next;
        		l2=l2->next;
        	}

        }
        //l2 completed   this has a more understanding structure
        	while(l1!=NULL) {
        		itr->next=l1;
        		itr=itr->next;
        		l1=l1->next;
        	}
                 // l1 completed
        	while(l2!=NULL) {
        	    
        		itr->next=l2;
        		itr=itr->next;
        		l2=l2->next;
        	}
        
        return res->next;
    }
};
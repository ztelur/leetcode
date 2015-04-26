#include <stdlib.h>
#include <iostream>
using namespace std;
//Sort a linked list in O(n log n) time using constant space complexity.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 * 还是使用归并方法，来进行排序，因为它是O(nlgn)的级别，而且对于快排是比较麻烦的啊	
 * 两次错误是在同一个地方啊，其实这并不是没有记住的问题啊，你想一想啊，还是你自己的思路不清晰的问题，
*	在merge中，没有对写指针进行赋值的啊，相当于你只动了读指针。。。。。。
	* 还有在命名的问题上也挺差的！！
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        // divide the line
        cout<<"sortList"<<" "<<head->val;
        ListNode* p1=head;
        ListNode* p2=head;
        ListNode* p3=head;
        while(p3!=NULL&&p3->next!=NULL) {
        	p1=p2;
        	p2=p2->next;
        	p3=p3->next->next;
        }
        p1->next=NULL;
        head=sortList(head);
        p2=sortList(p2);
        return merge(head,p2);
    }
    ListNode* merge(ListNode* head1,ListNode* head2) {
    	ListNode* head=new ListNode(1);
    	ListNode* itr=head;
    	while(head1!=NULL&&head2!=NULL) {
    		cout<<"merger"<<endl;
    		if (head1->val > head2->val) {
    			itr->next=head1;
    			itr=itr->next;
    			head1=head1->next;
    		} else {
    			itr->next=head2;
    			itr=itr->next;
    			head2=head2->next;
    		}
    	}
    	cout<<"before NULL"<<endl;
    	while(head1!=NULL) {
    		itr->next=head1;
    		itr=itr->next;
    		head1=head1->next;
    	}
    	cout<<"before two"<<endl;
    	while(head2!=NULL) {
    		itr->next=head2;
    		itr=itr->next;
    		head2=head2->next;
    	}
    	cout<<"dddd"<<endl;
    	return head->next;
    }
};
int main() {
	ListNode* head=new ListNode(2);
	ListNode* next=new ListNode(1);
	head->next=next;
	Solution solution;
	solution.sortList(head);
}

package leetcode.Copy_List_with_Random_Pointer;

import java.util.HashMap;

/**
 * Created by randy on 15-3-17.
 */


class RandomListNode {
      int label;
      RandomListNode next, random;
      RandomListNode(int x) { this.label = x; }
  };

public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head==null) {
            return null;
        }
        HashMap<RandomListNode,RandomListNode> hashMap=new HashMap<RandomListNode, RandomListNode>();
        RandomListNode newHead=new RandomListNode(head.label);
        hashMap.put(head,newHead);
        RandomListNode oldpreNode=head;
        RandomListNode newpreNode=newHead;
        RandomListNode curNode;
        while (oldpreNode.next!=null) {
            curNode=new RandomListNode(oldpreNode.next.label);
            hashMap.put(oldpreNode.next,curNode);
            newpreNode.next=curNode;

            oldpreNode=oldpreNode.next;
            newpreNode=curNode;
        }  //遍历过了一次
        oldpreNode=head;
        newpreNode=newHead;
        RandomListNode ranNode;
        do {
            if (oldpreNode.random!=null) {
                ranNode=hashMap.get(oldpreNode.random);
                newpreNode.random=ranNode;
            }
            oldpreNode=oldpreNode.next;
            newpreNode=newpreNode.next;

        } while (oldpreNode.next!=null);
        return newHead;
    }
}
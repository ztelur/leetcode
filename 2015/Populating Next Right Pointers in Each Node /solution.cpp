/**
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

//这两个假设很关键啊！！！！！！
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
    **/
//基本上还是使用层级遍历吧，对于普通的二叉树来说，
//对于完全二叉树，应该可以有其他的方法，比如数学方法来计算．
//
/**
 * 有一个上一个节点指针，然后进行ｂｆｓ遍历，每次把上一个节点的指针指向
 * 当前节点，然后进行转换啊．还要判断当前指针是否右侧没有东西啊，也就是
 * 是否进入了另外一个层啊
 *
 * 不对！！！，如果是想要层级遍历，那么必须存储不是常数级的数据啊！！
 * 和假设不符了，只有利用假设２的条件进行突破啦．
 * */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	TreeLinkNode *pre;
	int layer;
    void connect(TreeLinkNode *root) {
    }
	void bfs(TreeLinkNode *root,int layer) {
		
	}
};

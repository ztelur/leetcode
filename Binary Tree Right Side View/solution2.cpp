/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

搞不懂为什么要用层级遍历，bfs的一种变形。这题完全可以使用更加简单的方法。

更加通用的题目，遍历树节点中的每层的最后n个节点,而且，这里不是正数第几个
而是倒数第几个。。怎么使用层级的遍历呢？
是从右侧看过去，能看到的节点。是每一层的最后一个节点啊。
**/
#include <vector>
#include <stdlib.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    		vector<int> res;
		vector<TreeNode *> itr;
		//倒数最后一个，那么就是上一层的最后一个node的最后一个子节点。
		//如果是倒数2呢？由于有一个vector，其实就是size-2啦
		if (root==NULL) return res;
		itr.push_back(root);
		getNum(&res,itr);
    		return res;
	}
	void getNum(vector<int> *res,vector<TreeNode *> layer) {
		int len=layer.size();
		if (len==0) return;
		vector<TreeNode *> nextlayer;
		res->push_back(layer[len-]->val); //添加itr中最右边的啊。
		for(int i=0;i<len;i++) {  //遍历获得下一层的node
			if (layer[i]->left!=NULL) {
				nextlayer.push_back(layer[i]->left);
			}
			if (layer[i]->right!=NULL) {
				nextlayer.push_back(layer[i]->right);
			}
		}
		getNum(res,nextlayer);
	}
};


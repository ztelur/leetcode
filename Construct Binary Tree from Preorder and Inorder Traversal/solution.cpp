#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
	/* 1 preorder的第一个为root,从inorder中找到root,然后两边就是右子树和左子树
	 * 2 这是先迭代再组合的顺序
	 * 3 关键是如何计算右子树的定点的位置 loc+(split-left)+1
	 */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// if (preorder==NULL||preorder.size()==0) return NULL;
		int size=preorder.size();
		// printf("%s\n", "dddd");
		return dfs(preorder,0,size,inorder,0,size);		
    }
	TreeNode* dfs(const vector<int>& preorder,int loc,int size,const vector<int>& inorder,int left,int right) {
		printf("the loc is %d the size is %d the left is %d the right is %d \n",loc,size,left,right);
		TreeNode* root=new TreeNode(preorder[loc]);
		// if(right==left) return root;
		// if(right>left) return root;
		int split=find(inorder,root->val,left,right);
		if(loc+1<size) {
			root->left=dfs(preorder,loc+1,size,inorder,left,split);
		}
		if(loc+1+(split-left)<size) {
			root->right=dfs(preorder,loc+1+(split-left),size,inorder,split+1,right); 
		}
		return root;
	}
	int find(const vector<int>& list,int val,int left,int right) {
		for(int i=left;i<right;i++) {
			if(list[i]==val) return i;
		}
		return -1;
	}
	
};
int main() {
	vector<int> pre;
	pre.push_back(1);
	// pre.push_back(2);
	// pre.push_back(3);
	vector<int> in;
	// in.push_back(3);
	// in.push_back(2);
	in.push_back(1);
	Solution solution;
	// printf("%d\n",1);
	TreeNode* res=solution.buildTree(pre,in);
	printf("%d\n",res->val);
}
#include <stdlib.h>
#include <algorithm>
using namespace std;
/**
 * Definition for binary tree
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
    int res;
    int maxPathSum(TreeNode *root) {
 	    if(root!=NULL) {
 	    	res=root->val;
 	    	dfs(root);
 	    }   
 	    return res;
    }
    int dfs(TreeNode *root) {
    	if (root==NULL) {
    		return 0;
    	}
    	int leftMax=dfs(root->left);
    	int rightMax=dfs(root->right);
    	res=max(res,leftMax+rightMax+root->val);  //!!!!importance
    	return max(0,max(leftMax,rightMax)+root->val);
    }
};
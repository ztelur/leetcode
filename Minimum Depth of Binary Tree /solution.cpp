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
    int minDepth(TreeNode *root) {
	        return dfs(root);
    }
    int dfs(TreeNode * root) {
    	if (root!=NULL) {
    		return min(dfs(root->left),dfs(root->right))+1;	
    	}
      return 0;
    }
};
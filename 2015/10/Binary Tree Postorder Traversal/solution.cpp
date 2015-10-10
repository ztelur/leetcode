/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		innerPostorderTraversal(root,res);
		return res;
    }
	void innerPostorderTraversal(TreeNode* root,vector<int> &res) {
		if (root!=NULL) {
			innerPostorderTraversal(root->left,res);
			innerPostorderTraversal(root->right,res);
			res.push_back(root->val);
		}
	}
};

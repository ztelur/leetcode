/** Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 由于nums是排好序的,所以根据AVL树的性质.每次取中值作为root是一个好方法
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
		return buildAVL(0,len,nums);
    }
	TreeNode buildAVL(int left,int right,vector<int>& nums) {
		if (left >= right) return NULL;
		int mid=(left + right)/2;
		TreeNode * root=new TreeNode(nums[mid]);
		root->left=buildAVL(left,mid,nums);
		root->right=buildAVL(mid+1,right,nums);
		return root;
	}

};

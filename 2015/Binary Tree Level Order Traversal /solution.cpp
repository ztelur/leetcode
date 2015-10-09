/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]*/

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
	//层级遍历啊
	vector<vector<int>> *res;
    vector<vector<int>> levelOrder(TreeNode* root) {
		res=new vector<vector<int>>();
		if (root == NULL) return res;
		bfs(root);
		return res;
    }
	void bfs(TreeNode* root) {
		
	}
};

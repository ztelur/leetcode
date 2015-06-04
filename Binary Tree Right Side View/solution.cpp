/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
**/
#include <vector>
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
		while (root!=NULL) {
			res.push_back(root->val);
			if (root->right!=NULL) {
				root=root->right;
			} else {
				root=root->left;
			}
		}
	return res;	 
    }

};

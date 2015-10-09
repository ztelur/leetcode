#include <stdlib.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * 最简单的方法就是回溯法啦 **/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if (sum == 0) return true;
		if (root == NULL ) return false;
		bool success = hasPathSum(root->left,sum-root->val);
		if (!success) {
			success = hasPathSum(root->left,sum-root->val);
		}
		return success;
    }

};

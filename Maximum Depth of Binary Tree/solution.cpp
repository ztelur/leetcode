//
//Given a binary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//
//
#include <stdlib.h>
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
    int res;
    int maxDepth(TreeNode* root) {
   	  res=0;
   	  dfs(root,0);   
   	  return res;
    }
    void dfs(TreeNode* root,int depth) {
    	if (root==NULL) {
    		if (depth>res) res=depth;
    	}
    	dfs(root->left,depth+1);
    	dfs(root->right,depth+1);
    }
};
int main() {
	Solution solution;
	solution.maxDepth(NULL);
}
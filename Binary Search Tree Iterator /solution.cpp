#include <stack>
#include <stdlib.h>
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
class BSTIterator {
public:
    stack<TreeNode> smallest_list;
    BSTIterator(TreeNode *root) {
        while(root!=NULL) {
        	smallest_list.push(*root);
        	root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (smallest_list.empty()) {
        	return false;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {
        if(hasNext()) {
        	TreeNode result=smallest_list.top();
        	TreeNode *itr;
        	smallest_list.pop();
        	if ((itr=result.right)!=NULL) {
        		while(itr->left!=NULL) {
        			smallest_list.push(*itr);
        			itr=itr->left;
        		}
        		smallest_list.push(*itr);
        	}
        	return result.val;
        }
         
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 int main() {

 }
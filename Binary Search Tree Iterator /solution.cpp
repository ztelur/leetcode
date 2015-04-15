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
/**
	思路的问题，寻找最小值，需要从root往下寻找，但是输出结果的时候要从下往上，所以这样就完美的契合了stack的作用啊。
**/
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

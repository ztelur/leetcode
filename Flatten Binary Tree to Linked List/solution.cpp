/**Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 哎，其实就是先序遍历，然后使用一个队尾指针来连接．你想的
 * 右指针会被覆盖的问题，先保存一下不就完了吗．．．．．
 *
 * 而且要注意的是,原来的left指针都要清楚呢!!!!!!,而且要使用预先保存的right指针
 */
class Solution {
public:
  TreeNode *tail;
    void flatten(TreeNode* root) {
            dfs(root);
    }
  void dfs(TreeNode* root) {
    if (root==NULL) return;
    TreeNode *left=root->left;
    TreeNode *right=root->right;
    if (tail!=NULL) {
      tail->right=root;
      tail->left=NULL;
      tail=tail->right;

    } else {  //tail==NULL,说明是第一次啊
      tail=root;
        }
    dfs(root->left);
    dfs(right); //因为在dfs(root-left)中右指针会被更改的啊.
  }
};

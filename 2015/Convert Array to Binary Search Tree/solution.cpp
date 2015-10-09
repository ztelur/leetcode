/** Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/
/**
 *
 * 把数组转化为二叉收索树
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
    TreeNode* head;
	TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }
	void insert(int num) {
		insert(num,head);
	}
	bool contains(int num) {
		
	}
	int findMax() {
		
	}
	int findMin() {
	
	}
private:
	TreeNode* insert(int num,TreeNode *root) {
		if (root==NULL) {
			root=new TreeNode(num);	
		} else {
			if (num>root->val) {
				root->right=insert(num,root->right);
			} else if (num<root->val){
				root->left=insert(num,root->left);
			} 
		}
		return root;
	}
	//下边的insert是我自己写的啊.使用while语句啊,比较容易理解,但是
	//没有上边的那么简洁啊.
	void insert(int num,TreeNode *root) {
		if (root==NULL) {
			root=new TreeNode(num);
		} else {
			TreeNode *itr=root;
			while (itr!=NULL) {
				if (num > itr->val) {
					itr=itr->right;
				} else if (num < itr->val) {
					itr=itr->right;
				} else {
					break;
				}
			}
			if (itr==NULL) {
				itr=new TreeNode(num);
			}
		}
	}
	/**
	 * 删除有两个步骤啊,一,找到要删除的位置,
	 * 					二,处理删除之后导致的问题,通常是把右子树的最小值拿过来.*/
	TreeNode* remove(int num,TreeNode *root) {
		if (root == NULL) return root;
		if (num > root->val) {
			root->right=remove(num,root->right);
		} else if (num < root->val) {
			root->left=remove(num,root->left);
		} else {   //找到了.
			if (root->left != NULL && root->right != NULL ) {
				TreeNode* rightMin=findMin(root->right);
				root->val=rightMin->val;
				//这个迭代的方法还真是厉害啊,其实也是的啊.
				//虽然这样会导致性能降低,但是实现比较简单简介
				root->right=remove(rightMin-val,root->right);
			} else {
				root=(root->left==NULL)?root->left:root->right;
			}
			return root;
		}
	
	}
	//非递归的方法啊.
	TreeNode* findMax(TreeNode *root) {
		if (t!=NULL) {
			while (t.right!=NULL) {
				t=t.right;
			}
		}
		return t;
	}
	TreeNode* findMin(TreeNode *root) {
		if (root==NULL) return NULL;
		if (root->left!=NULL) {   //你如果这样写,那么就是要在这个函数外部保证
			//调用的root不为null,不然,你就要自己设置,但是一般为了健壮性,
			//你要在自己的函数中设置判断啊
			return findMin(root->left);
		} else {
			return root;
		}
	}

};

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return auxPathSum(root, sum);
    }
    
    bool auxPathSum(TreeNode* root, int sum) {
        if(root->left == NULL)
        {
            if(root->right == NULL)
                return (root->val == sum);
            else
            {
                return auxPathSum(root->right, sum-root->val);
            }
        }
        else
        {
            if(root->right == NULL)
                return auxPathSum(root->left, sum-root->val);
            else
                return (auxPathSum(root->left, sum-root->val) || auxPathSum(root->right, sum-root->val));       
        }
    }
};

// other people's solution
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if(root==nullptr)return false;
		if(sum==root->val&&root->left==nullptr&&root->right==nullptr) return true;
		return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
	}
};
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        return auxSym(left, right);
    }
    
    bool auxSym(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        
        if(left->val != right->val)
            return false;
        
        return(auxSym(left->left,right->right) && auxSym(left->right,right->left));
    }
};
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
    bool isBalanced(TreeNode* root) {
        int res = auxBalanced(root);
        if(res < 0)
            return false;
        else
            return true;
    }
    
    int auxBalanced(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int l = auxBalanced(root->left);
        int r = auxBalanced(root->right);
        if(l < 0 || r < 0 || abs(l-r)>1)
            return -1;
        return max(l,r)+1;
    }
};
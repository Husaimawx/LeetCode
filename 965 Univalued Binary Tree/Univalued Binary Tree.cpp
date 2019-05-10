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
    int num;
public:
    bool isUnivalTree(TreeNode* root) {
        num = root->val;
        return check(root);
    }
    
    bool check(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->val != num)
            return false;
        return (check(root->left) && check(root->right));
    }
};
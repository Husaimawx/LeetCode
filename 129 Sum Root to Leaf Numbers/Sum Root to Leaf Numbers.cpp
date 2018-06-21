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
    int res;
    int now;
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        res = 0;
        now = 0;
        sumNumbersAux(root);
        return res;
    }
    
    void sumNumbersAux(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            res += (now*10+root->val);
            return;
        }
        
        if(root->left != NULL)
        {
            now = now*10 + root->val;
            sumNumbersAux(root->left);
            now /= 10;
        }
        
        if(root->right != NULL)
        {
            now = now*10 + root->val;
            sumNumbersAux(root->right);
            now /= 10;
        }
        return;
    }
};
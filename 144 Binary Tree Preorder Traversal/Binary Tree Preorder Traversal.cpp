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
    vector<int> res;
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)
            return res;
        
        preorderTraversalAux(root);
        return res;
    }
    
    void preorderTraversalAux(TreeNode* root) {
        res.push_back(root->val);
        if(root->left)
            preorderTraversalAux(root->left);
        if(root->right)
            preorderTraversalAux(root->right);
        return;
    }
};
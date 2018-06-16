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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return res;
        
        postorderTraversalAux(root);
        return res;
    }
    
    void postorderTraversalAux(TreeNode* root) {
        if(root->left)
            postorderTraversalAux(root->left);
        if(root->right)
            postorderTraversalAux(root->right);
        res.push_back(root->val);
        return;
    }
};
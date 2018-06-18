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
    int max = 0;
    vector<int> res;
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return res;
        
        rightSideViewAux(root, 1);
        return res;
    }
    
    void rightSideViewAux(TreeNode* root, int level) {
        if(level > max)
        {
            max = level;
            res.push_back(root->val);
        }
        if(root->right != NULL)
            rightSideViewAux(root->right, level+1);
        if(root->left != NULL)
            rightSideViewAux(root->left, level+1);
        return;
    }
};
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
    map<TreeNode*, int> resmap;
    
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(resmap.find(root) != resmap.end())
            return resmap[root];
        
        int res1 = root->val;
        int res2 = 0;
        
        if(root->left != NULL)
        {
            res1+=rob(root->left->left);
            res1+=rob(root->left->right);
            res2+=rob(root->left);
        }
        
        if(root->right != NULL)
        {
            res1+=rob(root->right->left);
            res1+=rob(root->right->right);
            res2+=rob(root->right);
        }
        
        int res = (res1>res2) ? res1 : res2 ;
        resmap[root] = res;
        return res;
    }
};
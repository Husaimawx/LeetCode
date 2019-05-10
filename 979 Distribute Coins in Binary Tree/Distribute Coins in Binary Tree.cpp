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
    int distributeCoins(TreeNode* root) {
        return dfs(root)[0];
    }
    
    vector<int> dfs(TreeNode* root) {
        vector<int> res(2,0);
        if(root == NULL)
            return res;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        res[1] = (left[1]+right[1]+root->val-1);
        res[0] = left[0]+right[0]+abs(res[1]);
        return res;
    }
};
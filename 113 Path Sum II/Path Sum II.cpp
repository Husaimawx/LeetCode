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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        vector<int> temp;
        auxPathSum(root, sum, res, temp);
        return res;
    }
    
    void auxPathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& temp) {
        temp.push_back(root->val);
        if(root->left == NULL)
        {
            if(root->right == NULL)
            {
                if(root->val == sum)
                    res.push_back(temp);
            }
            else
            {
                auxPathSum(root->right, sum-root->val, res, temp);
            }
        }
        else
        {
            if(root->right == NULL)
                auxPathSum(root->left, sum-root->val, res, temp);
            else
            {
                auxPathSum(root->left, sum-root->val, res, temp);
                auxPathSum(root->right, sum-root->val, res, temp);    
            }
        }
        temp.pop_back();
    }
};
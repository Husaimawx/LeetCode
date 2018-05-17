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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        vector<int> num;
        travelTree(root, num);
        for(int i = 0;i<num.size()-1;i++)
        {
            if(num[i] >= num[i+1])
                return false;
        }
        return true;
    }
    
    void travelTree(TreeNode* root, vector<int>& num)
    {
        if(root == NULL)
            return;
        travelTree(root->left, num);
        num.push_back(root->val);
        travelTree(root->right, num);
    }
};
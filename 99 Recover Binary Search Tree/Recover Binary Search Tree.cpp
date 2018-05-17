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
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        vector<int> nums;
        getNum(root, nums);
        sort(nums.begin(), nums.end());
        inTraval(root, nums);
    }
    
    void getNum(TreeNode* root, vector<int>& nums)
    {
        if(root == NULL)
            return;
        getNum(root->left, nums);
        nums.push_back(root->val);
        getNum(root->right, nums);
    }
    
    void inTraval(TreeNode* root, vector<int>& nums)
    {
        if(root == NULL)
            return;
        inTraval(root->right, nums);
        root->val = nums[nums.size()-1];
        nums.pop_back();
        inTraval(root->left, nums);
    }
};
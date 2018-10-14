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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return constructMaximumBinaryTreeAux(nums,0,nums.size()-1);
    }
    
    TreeNode* constructMaximumBinaryTreeAux(vector<int>& nums, int from, int to)
    {
        if(from > to)
            return NULL;
        int max = nums[from];
        int maxpos = from;
        for(int i = from;i<=to;i++)
        {
            if(nums[i] > max)
            {
                max = nums[i];
                maxpos = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = constructMaximumBinaryTreeAux(nums,from,maxpos-1);
        root->right = constructMaximumBinaryTreeAux(nums,maxpos+1,to);
        return root;
    }
};
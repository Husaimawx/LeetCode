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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        
        return auxSortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* auxSortedArrayToBST(vector<int>& nums, int from, int to)
    {
        if(from > to)
            return NULL;
        int temp = (from+to)/2;
        TreeNode* head = new TreeNode(nums[temp]);
        head->left = auxSortedArrayToBST(nums, from, temp-1);
        head->right = auxSortedArrayToBST(nums, temp+1, to);
        return head;
    }
};
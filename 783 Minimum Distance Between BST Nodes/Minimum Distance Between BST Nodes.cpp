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
    vector<int> number;
public:
    int minDiffInBST(TreeNode* root) {
        search(root);
        int res = INT_MAX;
        for(int i = 1;i<number.size();i++) {
            res = min(res, number[i]-number[i-1]);
        }
        //for(int i = 0;i<number.size();i++)
        //    cout << number[i];
        return res;
    }
    
    void search(TreeNode* root) {
        if(root == NULL)
            return;
        search(root->left);
        number.push_back(root->val);
        search(root->right);
    }
};
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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        vector<int> res = auxPath(root);
        return res[0]-1;
    }
    
    vector<int> auxPath(TreeNode* root) {
        vector<int> res(3,0);
        if(root == NULL) {
            return res;
        }
        vector<int> left = auxPath(root->left);
        vector<int> right = auxPath(root->right);
        res[0] = max(left[0], right[0]);
        int temp = 1;
        if(left[1] == root->val)
            temp += left[2];
        if(right[1] == root->val)
            temp += right[2];
        res[0] = max(res[0], temp);
        res[1] = root->val;
        res[2] = 1;
        if(left[1] != root->val) {
            if(right[1] == root->val)
                res[2] += right[2];
        } else {
            if(right[1] != root->val) {
                res[2] += left[2];
            } else {
                res[2] += max(left[2], right[2]);
            }
        }
        return res;
    }
};
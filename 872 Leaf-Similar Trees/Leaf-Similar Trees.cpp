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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        sub(root1, res1);
        sub(root2, res2);
        if(res1.size() != res2.size())
            return false;
        for(int i = 0;i<res1.size();i++) {
            if(res1[i] != res2[i])
                return false;
        }
        return true;
    }
    
    void sub(TreeNode* root, vector<int>& res) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            res.push_back(root->val);
            return;
        }
        sub(root->left, res);
        sub(root->right, res);
        return;
    }
};
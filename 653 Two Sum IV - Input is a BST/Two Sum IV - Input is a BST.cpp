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
    map<int,int> M;
public:
    bool findTarget(TreeNode* root, int k) {
        aux(root);
        for(auto iter = M.begin();iter != M.end();iter++) {
            if(k == iter->first*2)
                continue;
            if(M.count(k-iter->first))
                return true;
        }
        return false;
    }
    
    void aux(TreeNode* root) {
        if(root == NULL)
            return;
        M[root->val] = 1;
        aux(root->left);
        aux(root->right);
    }
};
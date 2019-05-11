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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
            return false;
        vector<int> v1;
        vector<int> v2;
        dfs(root,x,v1);
        dfs(root,y,v2);
        if(v1.size() == v2.size() && v1[v1.size()-2] != v2[v2.size()-2])
            return true;
        return false;
    }
    
    bool dfs(TreeNode* root, int x, vector<int>& v) {
        v.push_back(root->val);
        if(root->val == x)
            return true;
        if(root->left != NULL) {
            if(dfs(root->left,x,v))
                return true;
        }
        if(root->right != NULL) {
            if(dfs(root->right,x,v))
                return true;
        }
        v.pop_back();
        return false;
    }
};
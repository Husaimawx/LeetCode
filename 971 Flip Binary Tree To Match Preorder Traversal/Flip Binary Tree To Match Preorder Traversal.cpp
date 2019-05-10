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
    int from = 0;
    vector<int> v;
    vector<int> res;
    int flag = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        v = voyage;
        dfs(root);

        if(from != v.size() || flag == -1) {
            res.resize(1);
            res[0] = -1;
            return res;
        }
        return res;
    }
    
    void dfs(TreeNode* root) {
        if(root == NULL)
            return;
        if(from == v.size() || root->val != v[from]) {
            flag = -1;
            return;
        }
        from+=1;
        if(root->right != NULL && root->left != NULL) {
            if(root->right->val == v[from]) {
                TreeNode* temp = root->left;
                root->left = root->right;
                root->right = temp;
                res.push_back(root->val);
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
};
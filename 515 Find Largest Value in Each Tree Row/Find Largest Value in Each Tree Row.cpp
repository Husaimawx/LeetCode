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
vector<int> res;
    
public:
    vector<int> largestValues(TreeNode* root) {
        DFS(0,root);
        return res;
    }
    
    void DFS(int depth, TreeNode* root)
    {
        if(root == NULL)
            return;
        if(depth == res.size())
            res.push_back(root->val);
        else
            if(root->val > res[depth])
                res[depth] = root->val;
        DFS(depth+1, root->left);
        DFS(depth+1, root->right);
    }
};
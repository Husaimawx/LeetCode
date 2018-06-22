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
    vector<int> path;
    vector<string> res;
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return res;
        binaryTreePathsAux(root);
        
        return res;
    }
    
    void binaryTreePathsAux(TreeNode* root)
    {
        path.push_back(root->val);
        if(root->left != NULL)
            binaryTreePathsAux(root->left);
        if(root->right != NULL)
            binaryTreePathsAux(root->right);
        
        if(root->left == NULL && root->right == NULL)
        {
            string temp = to_string(path[0]);
            for(int i = 1;i<path.size();i++)
            {
                temp = temp + "->" + to_string(path[i]);
            }
            res.push_back(temp);
        }
        
        path.pop_back();
        return;
    }
    
};
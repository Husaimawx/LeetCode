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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* temp;
        while(1)
        {
            if(root->left == NULL && root->right == NULL)
                return;
            else if(root->left == NULL)
                root = root->right;
            else
            {
                temp = root->left;
                while(temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }   
    }
};
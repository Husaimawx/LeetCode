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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* res = new TreeNode(val);
            return res;
        }
        change(root, val);
        return root;
    }
    
    void change(TreeNode* root, int val) {
        if(root->val < val) {
            if(root->right == NULL) {
                TreeNode* res = new TreeNode(val);
                root->right = res;
                return;
            }
            change(root->right, val);
        } else {
            if(root->left == NULL) {
                TreeNode* res = new TreeNode(val);
                root->left = res;
                return;
            }
            change(root->left, val);            
        }
    }
};
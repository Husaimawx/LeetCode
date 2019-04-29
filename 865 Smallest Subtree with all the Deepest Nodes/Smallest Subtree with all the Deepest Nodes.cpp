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
    map<TreeNode*, int> M;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL)
            return NULL;
        traverse(root);
        TreeNode* res = root;
        while(1) {
            if(res->left == NULL && res->right == NULL)
                return res;
            if(res->left == NULL)
                res = res->right;
            else if(res->right == NULL)
                res = res->left;
            else if(M[res->left] == M[res->right])
                return res;
            else if(M[res->left] < M[res->right])
                res = res->right;
            else
                res = res->left;
        }
    }
    
    void traverse(TreeNode* root) {
        int left = 0,right = 0;
        if(root->left != NULL) {
            traverse(root->left);
            left = M[root->left];
        }
        if(root->right != NULL) {
            traverse(root->right);
            right = M[root->right];
        }
        M[root] = max(left, right)+1;
        return;
    }
};
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
    int minCameraCover(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->val != 0)
            return root->val;
        if(root->left == NULL && root->right == NULL)
            return 1;

        int res1 = 1;
        if(root->left != NULL)
            res1 += minCameraCover(root->left->left) + minCameraCover(root->left->right);
        if(root->right != NULL)
            res1 += minCameraCover(root->right->left) + minCameraCover(root->right->right);
        
        int res2;
        if(root->left == NULL) {
            res2 = INT_MAX;
        } else {
            res2 = 1+minCameraCover(root->right);
            if(root->left->left != NULL)
                res2 += min(minCameraCover(root->left->left->left)+minCameraCover(root->left->left->right),minCameraCover(root->left->left));
            if(root->left->right != NULL)
                res2 += min(minCameraCover(root->left->right->left)+minCameraCover(root->left->right->right),minCameraCover(root->left->right));
        }

        int res3;
        if(root->right == NULL) {
            res3 = INT_MAX;
        } else {
            res3 = 1+minCameraCover(root->left);
            if(root->right->left != NULL)
                res3 += min(minCameraCover(root->right->left->left)+minCameraCover(root->right->left->right),minCameraCover(root->right->left));
            if(root->right->right != NULL)
                res3 += min(minCameraCover(root->right->right->left)+minCameraCover(root->right->right->right),minCameraCover(root->right->right));
        }
        
        int res = min(res1,min(res2,res3));
        root->val = res;
        return res;
    }
};
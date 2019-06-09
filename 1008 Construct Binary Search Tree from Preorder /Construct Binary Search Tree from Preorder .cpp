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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1)
            return root;
        
        int i;
        for(i = 1;i<preorder.size();i++) {
            if(preorder[i] > preorder[0])
                break;
        }
        vector<int> left(preorder.begin()+1,preorder.begin()+i);
        vector<int> right(preorder.begin()+i,preorder.end());
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};
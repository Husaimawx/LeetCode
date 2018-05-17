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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        if(preorder.size() == 0)
            return root;
        return auxBuildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* auxBuildTree(vector<int>& preorder, int from1, int to1, vector<int>& inorder, int from2, int to2)
    {
        if(from1 > to1)
            return NULL;
        TreeNode* root = new TreeNode(preorder[from1]);
        int temp;
        for(temp = from2; temp<=to2;temp++)
        {
            if(preorder[from1] == inorder[temp])
                break;
        }
        root->left = auxBuildTree(preorder, from1+1, temp+from1-from2, inorder, from2, temp-1);
        root->right = auxBuildTree(preorder, to1+temp+1-to2, to1, inorder, temp+1, to2);
        return root;
    }
};
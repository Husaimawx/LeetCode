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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        if(inorder.size() == 0)
            return root;
        return auxBuildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);        
    }
    
    TreeNode* auxBuildTree(vector<int>& inorder, int from1, int to1, vector<int>& postorder, int from2, int to2)
    {
        if(from1 > to1)
            return NULL;
        TreeNode* root = new TreeNode(postorder[to2]);
        int temp;
        for(temp = from1; temp<=to1;temp++)
        {
            if(postorder[to2] == inorder[temp])
                break;
        }
        root->left = auxBuildTree(inorder, from1, temp-1, postorder, from2, from2+temp-1-from1); 
        root->right = auxBuildTree(inorder, temp+1, to1, postorder, to2-to1+temp, to2-1); 
        return root;
    }
};
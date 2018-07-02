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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;

        TreeNode* treeList[100];
        treeList[0] = root;
        int i;
        for(i = 0;treeList[i] != NULL;i++)
        {
            if(treeList[i]->val == key)
                break;
            else if(treeList[i]->val > key)
                treeList[i+1] = treeList[i]->left;
            else
                treeList[i+1] = treeList[i]->right;
        }
        if(treeList[i] == NULL)
            return root;

        TreeNode* temp = treeList[i];
        if(temp->right == NULL)
        {
            if(i == 0)
                return temp->left;
            else if(treeList[i-1]->left == temp)
                treeList[i-1]->left = temp->left;
            else
                treeList[i-1]->right = temp->left;
        }
        else
        {
            temp = temp->right;
            while(temp->left != NULL && temp->left->left != NULL)
                temp = temp->left;
            if(temp->left == NULL)
            {
                treeList[i]->val = temp->val;
                treeList[i]->right = temp->right;
            }
            else
            {
                treeList[i]->val = temp->left->val;
                temp->left = temp->left->right;
            }
        }
        
        return root;
    }
};
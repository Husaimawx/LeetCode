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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* plist[100];
        TreeNode* qlist[100];
        findPath(root, p, plist,0);
        findPath(root, q, qlist,0);
        for(int i = 0;i<100;i++)
        {
            if(plist[i] != qlist[i])
                return plist[i-1];
        }
    }
    
    void findPath(TreeNode* root, TreeNode* p, TreeNode** plist, int from)
    {
        plist[from] = root;
        if(root == p)
            return;
        if(p->val > root->val)
            findPath(root->right,p,plist,from+1);
        else
            findPath(root->left,p,plist,from+1);
        return;
    }
};
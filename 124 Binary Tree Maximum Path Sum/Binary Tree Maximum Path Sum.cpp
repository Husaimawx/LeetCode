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
    map<TreeNode*, int> one;
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        one[NULL] = 0;
        onePath(root);
        twoPath(root);
        //cout << one[root->left];
        //cout << one[root->right];
        //cout << root->val;
        return res;
    }
    
    int onePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sub = max(onePath(root->left),onePath(root->right));
        sub = max(sub,0);
        one[root] = root->val + sub;
        return one[root];
    }
    
    void twoPath(TreeNode* root) {
        if(root == NULL)
            return;
        int left = max(0,one[root->left]);
        int right = max(0,one[root->right]);
        res = max(res,left+right+root->val);
        twoPath(root->left);
        twoPath(root->right);
        return;
    }
};
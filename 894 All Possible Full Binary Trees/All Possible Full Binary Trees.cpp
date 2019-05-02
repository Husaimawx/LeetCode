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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N == 1) {
            TreeNode* root = new TreeNode(0);
            res.push_back(root);
            return res;
        }
        vector<vector<TreeNode*>> store;
        for(int i = 1;i<N;i++) {
            store.push_back(allPossibleFBT(i));
        }
        
        for(int i = 1;i<N-1;i++) {
            int a = i;
            int b = N-1-a;
            a -= 1;
            b -= 1;
            for(auto d1 : store[a]) {
                for(auto d2 : store[b]) {
                    TreeNode* root = new TreeNode(0);
                    root->left = d1;
                    root->right = d2;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
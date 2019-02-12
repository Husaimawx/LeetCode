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
    int widthOfBinaryTree(TreeNode* root) {
        vector<long long> v;
        vector<TreeNode*> t;
        if(root == NULL)
            return 0;
        
        v.push_back(0);
        t.push_back(root);
        int from = 0;
        long long res = 0;
        while(from != v.size()) {
            int to = v.size();
            res = max(res, v[to-1]-v[from]);
            long long temp = v[from];
            for(int i = from;i<to;i++) {
                v[i] -= temp;
            }
            for(int i = from;i<to;i++) {
                if(t[i]->left != NULL) {
                    v.push_back(v[i]*2);
                    t.push_back(t[i]->left);
                }
                if(t[i]->right != NULL) {
                    v.push_back(v[i]*2+1);
                    t.push_back(t[i]->right);                    
                }
            }
            from = to;
        }
        return res+1;
    }
};
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
    bool isCompleteTree(TreeNode* root) {
        int stop = 0;
        if(root == NULL)
            return true;
        vector<TreeNode*> v(1,root);
        int from = 0;
        while(from != v.size()) {
            int to = v.size();
            for(int i = from;i<to;i++) {
                if(v[i]->left != NULL) {
                    if(stop)
                        return false;
                    v.push_back(v[i]->left);
                } else {
                    stop = 1;
                }
                if(v[i]->right != NULL) {
                    if(stop)
                        return false;
                    v.push_back(v[i]->right);
                } else {
                    stop = 1;
                }
            }
            from = to;
        }
        return true;
    }
};
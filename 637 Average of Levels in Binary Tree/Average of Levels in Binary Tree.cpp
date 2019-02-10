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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        vector<TreeNode*> v;
        v.push_back(root);
        int from = 0;
        while(from != v.size()) {
            int to = v.size();
            double sum = 0;
            for(int i = from;i<to;i++) {
                if(v[i]->left != NULL)
                    v.push_back(v[i]->left);
                if(v[i]->right != NULL)
                    v.push_back(v[i]->right);
                sum += v[i]->val;
            }
            sum /= (to-from);
            res.push_back(sum);
            from = to;
        }
        return res;
    }
};
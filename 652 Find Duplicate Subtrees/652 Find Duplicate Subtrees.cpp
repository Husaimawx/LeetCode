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
    map<TreeNode*, string> M;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        aux(root);
        map<string, int> M2;
        vector<TreeNode*> res;
        for(auto iter = M.begin();iter != M.end();iter++) {
            if(M2.count(iter->second)) {
                if(M2[iter->second] == 1)
                    res.push_back(iter->first);
                M2[iter->second] += 1;
            }
            else
                M2[iter->second] = 1;
            //cout << iter->second << endl;
        }
        return res;
    }
    
    string aux(TreeNode* root) {
        if(root == NULL)
            return "#";
        string s1 = aux(root->left);
        string s2 = aux(root->right);
        M[root] = to_string(root->val)+s1+s2;
        return M[root];
    }
};
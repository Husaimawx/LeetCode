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
    vector<string> v;
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<int> s;
        dfs(root,s);
        string res = v[0];
        for(int i = 1;i<v.size();i++) {
            if(res > v[i])
                res = v[i];
        }
        return res;
    }
    
    void dfs(TreeNode* root,vector<int>& s) {
        s.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            string temp = "";
            for(int i = s.size()-1;i>=0;i--) {
                char t = 'a'+s[i];
                temp = temp + t;
            }
            v.push_back(temp);
            s.resize(s.size()-1);
            return;
        }
        if(root->left != 0) {
            dfs(root->left,s);
        }
        if(root->right != 0) {
            dfs(root->right,s);
        }
        s.resize(s.size()-1);
        return;        
    }
};
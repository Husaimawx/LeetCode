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
    vector<int> res;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> path;
        find(root, target, path);
        //for(int i = 0;i<path.size();i++)
        //    cout << path[i]->val;
        for(int i = 0;i<path.size();i++) {
            //cout << path[i]->val;
            if(i+1 != path.size()) {
                if(path.size()-1-i < K) {
                    TreeNode* other;
                    if(path[i]->left == path[i+1])
                        other = path[i]->right;
                    else
                        other = path[i]->left;
                    getres(other, K-(path.size()-i));
                } else if(path.size()-1-i == K) {
                    res.push_back(path[i]->val);
                }
            }
            else {
                getres(target, K);
            }
        }
        return res;
    }
    
    void getres(TreeNode* root, int K) {
        if(K < 0 || root == NULL)
            return;
        if(K == 0) {
            res.push_back(root->val);
            return;
        }
        getres(root->left, K-1);
        getres(root->right, K-1);
    }
    
    bool find(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(root == NULL)
            return false;
        if(root->val == target->val) {
            path.push_back(target);
            return true;
        }
        path.push_back(root);
        if(find(root->left, target, path))
            return true;
        if(find(root->right,target, path))
            return true;
        path.resize(path.size()-1);
        return false;
    }
};
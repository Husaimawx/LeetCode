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
    map<int,int> M;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for(int i = 0;i<post.size();i++) {
            M[post[i]] = i;
        }
        return aux(pre, post, 0, pre.size()-1, 0, post.size()-1);
    }
    
    TreeNode* aux(vector<int>& pre, vector<int>& post, int from1, int to1, int from2, int to2) {
        if(from1 > to1)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[from1]);
        if(from1 == to1)
            return root;
        root->left = aux(pre, post, from1+1, from1+1+M[pre[from1+1]]-from2,from2, M[pre[from1+1]]);
        root->right = aux(pre, post, from1+1+M[pre[from1+1]]-from2+1, to1, M[pre[from1+1]]+1, to2-1);
        return root;
    }
};
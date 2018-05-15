/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        subIT(root, res);
        return res;
    }
    
    void subIT(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
            return;
        subIT(root->left, res);
        res.push_back(root->val);
        subIT(root->right, res);
        return;
    }
};

// iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(!st.empty() || node) {
            while(node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        } 
        return res;
    }
};
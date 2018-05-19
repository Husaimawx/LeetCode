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
    int kthSmallest(TreeNode* root, int k) {
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
            k--;
            if(k == 0)
                return node->val;
            node = node->right;
        }
    }
};
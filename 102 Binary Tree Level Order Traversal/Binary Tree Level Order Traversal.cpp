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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        deque<TreeNode*> s;
        s.push_back(root);
        
        TreeNode* node;
        while(s.size() != 0)
        {
            vector<int> line;
            int len = s.size();
            for(int i = 0;i<len;i++)
            {
                node = s.front();
                line.push_back(node->val);
                s.pop_front();
                if(node->left)
                    s.push_back(node->left);
                if(node->right)
                    s.push_back(node->right);
            }
            
            res.push_back(line);
        }
        return res;
    }
};
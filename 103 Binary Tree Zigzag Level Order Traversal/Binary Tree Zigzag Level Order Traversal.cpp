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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        deque<TreeNode*> q;
        q.push_back(root);
        
        int level = 0;
        
        while(!q.empty())
        {
            vector<int> line;
            TreeNode* node;
            
            int sz = q.size();
            for(int i = 0;i<sz;i++)
            {
                if(level == 1)
                {
                    node = q.back();
                    q.pop_back();
                    if(node->right)
                        q.push_front(node->right);
                    if(node->left)
                        q.push_front(node->left);
                }
                else
                {
                    node = q.front();
                    q.pop_front();
                    if(node->left)
                        q.push_back(node->left);   
                    if(node->right)
                        q.push_back(node->right);                   
                }
                line.push_back(node->val);
            }
        
            
            level = 1-level;
            res.push_back(line);
        }
        return res;
    }
};
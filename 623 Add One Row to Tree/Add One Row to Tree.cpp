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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* nroot = new TreeNode(v);
            nroot->left = root;
            return nroot; 
        }
        
        vector<TreeNode*> line;
        line.push_back(root);
        int from = 0;
        for(int i = 1;i<d-1;i++) {
            int temp = line.size();
            for(int j = from;j<temp;j++) {
                if(line[j]->left != NULL) {
                    line.push_back(line[j]->left);
                }
                if(line[j]->right != NULL) {
                    line.push_back(line[j]->right);
                }
            }
            from = temp;
        }
        for(int i = from;i<line.size();i++) {
            TreeNode* temp = line[i]->left;
            line[i]->left = new TreeNode(v);
            line[i]->left->left = temp;
            temp = line[i]->right;
            line[i]->right = new TreeNode(v);
            line[i]->right->right = temp;
        }
        return root;
    }
};
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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res = findBottomLeftValueAux(root);
        return res[0];
    }
    
    vector<int> findBottomLeftValueAux(TreeNode* root)
    {
        vector<int> res(2,0);
        if(root == NULL)
            return res;
        
        vector<int> resleft = findBottomLeftValueAux(root->left);
        vector<int> resright = findBottomLeftValueAux(root->right);
        if(resleft[1]<resright[1])
        {
            res[0] = resright[0];
            res[1] = resright[1]+1;
        }
        else if(resleft[1]>resright[1])
        {
            res[0] = resleft[0];
            res[1] = resleft[1]+1;           
        }
        else
        {
            res[1] = resleft[1]+1;
            if(resleft[1] == 0)
            {
                res[0] = root->val;
            }
            else
            {
                res[0] = resleft[0];
            }
        }
        return res;
    }
};
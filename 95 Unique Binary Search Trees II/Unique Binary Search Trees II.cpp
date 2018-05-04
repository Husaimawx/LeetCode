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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        {
            vector<TreeNode*> res;
            return res;
        }
        
        return generateTrees2(n, 0);
    }
    
    vector<TreeNode*> generateTrees2(int n, int base)
    {
        vector<TreeNode*> res;
        if(n == 0)
        {
            res.push_back(NULL);
            return res;
        }
        
        if(n == 1)
        {
            TreeNode* temp = new TreeNode(base+1);
            res.push_back(temp);
            return res;           
        }
        else
        {
            vector<TreeNode*> left;
            vector<TreeNode*> right;
            TreeNode* temp;
            for(int i = 1;i<=n;i++)
            {
                left = generateTrees2(i-1,base);
                right = generateTrees2(n-i,i+base);
                for(auto iter1 = left.begin(); iter1 != left.end(); iter1++)
                {
                    for(auto iter2 = right.begin(); iter2 != right.end(); iter2++)
                    {
                        temp = new TreeNode(i+base);
                        temp->left = (*iter1);
                        temp->right = (*iter2);
                        res.push_back(temp);
                    }
                }
            }
            return res;
        }
    }
};
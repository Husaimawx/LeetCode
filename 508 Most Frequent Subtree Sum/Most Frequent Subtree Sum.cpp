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
unordered_map<int,int> M;
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        findFrequentTreeSumAux(root);
        int max = 0;
        for(auto iter = M.begin();iter != M.end();iter++)
        {
            if(iter->second > max)
            {
                max = iter->second;
                res.resize(0);
                res.push_back(iter->first);
            }
            else if(iter->second == max)
            {
                res.push_back(iter->first);
            }
        }
        return res;
    }
    
    int findFrequentTreeSumAux(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = findFrequentTreeSumAux(root->left);
        int right = findFrequentTreeSumAux(root->right);
        int sum = root->val+left+right;
        if(M.count(sum) == 0)
            M[sum] = 1;
        else
            M[sum] += 1;
        return sum;
    }
};
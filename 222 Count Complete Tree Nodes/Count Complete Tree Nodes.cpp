/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// My solution
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* temp = root->left;
        int from = 1;
        while(temp != NULL)
        {
            temp = temp->left;
            from *= 2;
        }
        int to = from*2-1;
        while(from < to)
        {
            int temp = (from+to+1)/2;
            if(checkNum(root, temp))
            {
                from = temp;
            }
            else
            {
                to = temp-1;
            }
        }
        return from;
    }
    
    bool checkNum(TreeNode* root, int temp)
    {
        vector<int> a(33,0);
        int i;
        for(i = 0; temp!=1;i++)
        {
            a[i] = temp%2;
            temp /= 2;
        }
        i--;
        while(i>=0)
        {
            if(a[i])
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
            i--;
        }
        if(root == NULL)
            return false;
        else
            return true;
    }
};

// Other people's good solution
class Solution {
public:
    int countNodes(TreeNode* root, int hl=0, int hr=0) {
        if(!root) return 0;
        TreeNode *l=root, *r=root;
        if(!hl)   while(l) {hl++;l=l->left;}
        if(!hr)   while(r) {hr++;r=r->right;}
        if(hl==hr) return (1<<hl)-1;
        return 1+countNodes(root->left,hl-1,0)+countNodes(root->right,0,hr-1); 
    }
};
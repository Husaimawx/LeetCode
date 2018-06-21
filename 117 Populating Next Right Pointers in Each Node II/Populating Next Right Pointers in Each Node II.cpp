/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// my solution
class Solution {
public:
    vector<TreeLinkNode*> leftlist;
    vector<TreeLinkNode*> rightlist;
    
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        
        connect(root->left);
        leftlist.resize(0);
        rightlist.resize(0);
        connect(root->right);
        leftlist.resize(0);
        rightlist.resize(0);
        
        TreeLinkNode* left = root->left;
        TreeLinkNode* right = root->right;
        
        makeRight(left,1);
        makeLeft(right,1);
        
        if(leftlist.size() > rightlist.size())
        {
            int len = rightlist.size();
            for(int i = 0;i<len;i++)
            {
                rightlist[i]->next = leftlist[i];    
            }
        }
        else
        {
            int len = leftlist.size();
            
            for(int i = 0;i<len;i++)
            {
                rightlist[i]->next = leftlist[i];    
            }  
            for(int i = len;i<rightlist.size();i++)
            {
                rightlist[i]->next = NULL;
            }
        }

        return;
    }
    
    void makeRight(TreeLinkNode* root, int level)
    {
        if(root == NULL)
            return;
        if(level > rightlist.size())
            rightlist.push_back(root);
        makeRight(root->right, level+1);
        makeRight(root->left, level+1);
        return;
    }
    
    void makeLeft(TreeLinkNode* root, int level)
    {
        if(root == NULL)
            return;
        if(level > leftlist.size())
            leftlist.push_back(root);
        makeLeft(root->left, level+1);
        makeLeft(root->right, level+1);
        return;
    }
};

// other people's solution
// just level order travel, record the first and last element of a single layer
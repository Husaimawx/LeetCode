// Other people's code
class BSTIterator {
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {            
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.empty() ? false : true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode*smallest;
     
        smallest=s.top();
        s.pop();
                
        if(smallest->right!=NULL)
        {
            TreeNode*tmp=smallest->right;
            while(tmp)
            {
                s.push(tmp);
                tmp=tmp->left;
            }
        }

        return smallest->val;
    }
};

// My code
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:    
    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode *root) {
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        
        TreeNode* temp2 = temp->right;
        if(temp2 != NULL)
        {
            s.push(temp2);
            while(temp2->left != NULL)
            {
                temp2 = temp2->left;
                s.push(temp2);
            }
        }
        
        return temp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
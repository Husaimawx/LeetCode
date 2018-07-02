/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#,";
        string res = to_string(root->val);
        res += ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    TreeNode* deserialize(string data) {
        int found = 0;
        int oldfound = 0;
        int val;

        stack<TreeNode*> tree;
        TreeNode* root = NULL;
        TreeNode* temp;
        int flag = 1;
        int lorr = 0;

        while (1)
        {
            found = data.find(",", oldfound);
            if (found == -1)
                return root;
            if (data[found - 1] == '#')
            {
                if (flag == 1)
                    return NULL;
                else
                {
                    if (lorr == 0)
                        lorr = 1;
                    else
                    {
                        tree.pop();
                    }
                }
            }
            else
            {
                val = atoi(data.substr(oldfound, found).c_str());
                if (flag == 1)
                {
                    root = new TreeNode(val);
                    flag = 0;
                    tree.push(root);
                }
                else
                {
                    temp = tree.top();
                    if (lorr == 0)
                    {
                        temp->left = new TreeNode(val);
                        tree.push(temp->left);
                    }
                    else
                    {
                        temp->right = new TreeNode(val);
                        lorr = 0;
                        tree.pop();
                        tree.push(temp->right);
                    }
                }
            }
            oldfound = found+1;
        }
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
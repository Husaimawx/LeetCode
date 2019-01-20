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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        
        return (to_string(root->val) + ","+ serialize(root->left) +","+serialize(root->right));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        if(data.size() == 0)
            return NULL;
        vector<int> newdata;
        int from = 0;
        while(from < data.size()) {
            int pos = data.find(',',from);
            //cout << pos << endl;
            
            if(pos == -1)
                pos = data.size();
            if(from != pos)
                newdata.push_back(stoi(data.substr(from, pos-from)));
            from = pos+1;
        }
        for(int i = 0;i<newdata.size();i++)
            cout << newdata[i];
        return deserializeAux(newdata, 0);
    }
    
    TreeNode* deserializeAux(vector<int>& data, int from) {
        stack<TreeNode*> st;
        TreeNode* head = new TreeNode(data[0]);
        st.push(head);
        for(int i = 1;i<data.size();i++) {
            if(data[i] < st.top()->val) {
                st.top()->left = new TreeNode(data[i]);
                st.push(st.top()->left);
            } else {
                while(1) {
                    TreeNode* temp = st.top();
                    st.pop();
                    if(st.size() == 0 || st.top()->val > data[i]) {
                        temp->right = new TreeNode(data[i]);
                        st.push(temp->right);
                        break;
                    }
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        vector<vector<Node*>> help;
        vector<Node*> temp;
        temp.push_back(root);
        help.push_back(temp);
        while(temp.size() != 0) {
            vector<Node*> temp2;
            for(int i = 0;i<temp.size();i++) {
                for(int t = 0;t<temp[i]->children.size();t++)
                    temp2.push_back(temp[i]->children[t]);
            }
            if(temp2.size() != 0)
                help.push_back(temp2);
            temp = temp2;
        }
        
        for(int i = 0;i<help.size();i++) {
            vector<int> temp3;
            for(int j = 0;j<help[i].size();j++) {
                temp3.push_back(help[i][j]->val);
            }
            res.push_back(temp3);
        }
        return res;
    }
};
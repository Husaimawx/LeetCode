class Solution {
    
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "")
            return false;
        
        int start = 0;
        int done = 0;
        stack<int> node;
        node.push(0);
        while(1)
        {
            if(preorder[start] == '#')
            {
                node.pop();
                if(node.size() == 0)
                    done = 1;
            }
            else
            {
                node.push(0);
            }
            start = preorder.find(",",start)+1;
            
            if(start == 0)
            {
                break;
            }
            else
            {
                if(done == 1)
                    return false;
            }
        }
        if(node.size() == 0)
            return true;
        else
            return false;
    }
    
};
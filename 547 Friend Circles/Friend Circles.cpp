
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        if(len == 0)
            return 0;
        
        vector<int> hashtable(len,0);
        int num_done = 0;
        int res = 0;
        
        while(num_done != len)
        {
            res += 1;
            queue<int> q;
            for(int i = 0;i<len;i++)
            {
                if(hashtable[i] == 0)
                {
                    q.push(i);
                    num_done++;
					hashtable[i] = 1;
                    break;
                }
            }
            while(!q.empty())
            {
                for(int i = 0;i<len;i++)
                {
                    if(i == q.front())
                        continue;
                    if(hashtable[i] == 0 && M[i][q.front()] == 1)
                    {
                        q.push(i);
                        num_done++;
                        hashtable[i] = 1;
                    }
                }
                q.pop();
            }
        }
        
        return res;
    }
};
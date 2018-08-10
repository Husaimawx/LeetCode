class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.size() == 0)
        {
            string s("0A0B");
            return s;
        }
        
        int num = 0;
        int num2 = 0;
        vector<int> snum(10,0);
        vector<int> gnum(10,0);
        
        for(int i = 0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])
                num++;
            snum[secret[i]-'0']++;
            gnum[guess[i]-'0']++;
        }
        
        for(int i = 0;i<10;i++)
        {
            if(snum[i] < gnum[i])
                num2 += snum[i];
            else
                num2 += gnum[i];
        }
        num2-=num;
        string s = to_string(num)+"A"+to_string(num2)+"B";
        return s;
    }
};
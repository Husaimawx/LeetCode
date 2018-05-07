class Solution {
public
    string getPermutation(int n, int k) {
        if(n == 1)
            return 1;
        k--;
        vectorint fab(n-1,1);
        vectorint numleft(n,0);
        string res = ;
        for(int i = 0;in;i++)
        {
            numleft[i] = i+1;
        }
        for(int i = 1;in-1;i++)
        {
            fab[i] = fab[i-1](i+1);
        }
        
        int temp;
        for(int i = n-2;i=0;i--)
        {
            temp = kfab[i];
            res += to_string(numleft[temp]);
            k = k%fab[i];
            numleft.erase(numleft.begin()+temp);
        }
        res += to_string(numleft[0]);
        return res;
    }
};
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> numlist;
        while(n != 0)
        {
            numlist.push_back(n % 10);
            n = n/10;
        }
        int i;
        for(i = 0;i<numlist.size()-1;i++)
        {
            if(numlist[i] > numlist[i+1])
                break;
        }
        if(i == numlist.size()-1)
            return -1;
        i++;
        int j;
        for(j = 0;j<i;j++)
        {
            if(numlist[j] > numlist[i])
                break;
        }
        swap(numlist[i],numlist[j]);
        int k = 0;
        int t = i-1;
        while(k < t)
        {
            swap(numlist[k],numlist[t]);
            k++;
            t--;
        }
        long long int res = 0;
        for(int i = numlist.size()-1;i>=0;i--)
        {
            res = res*10 + numlist[i];
        }
        if(res > (long long int)INT_MAX)
            return -1;
        else
            return res;
    }
};
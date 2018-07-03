// my solution
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<vector<int>> numbers;
        for(int i = 0;i<nums.size();i++)
        {
            numbers.push_back(nums[i]);
        }
        
        vector<int> temp;
        for(int i = 0;i<numbers.size();i++)
        {
            for(int j = i+1;j<numbers.size();j++)
            {
                if(comp(i,j,numbers) == -1)
                {
                    temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
        
        string res;
        for(int i = 0;i<numbers.size();i++)
        {
            res = res+to_string(numbers[i][0]);
        }
        return res;
    }
    
    int comp(int i, int j, vector<vector<int>>& numbers)
    {
        int t;
        for(t = 0;t<numbers[i][1] && t<numbers[j][1];t++)
        {
            if(numbers[i][numbers[i][1]+1-t] < numbers[j][numbers[j][1]+1-t])
                return -1;
            else if(numbers[i][numbers[i][1]+1-t] < numbers[j][numbers[j][1]+1-t])
                return 1;
        }
        
        vector<int> aux;
        if(t == numbers[i][1])
        {
            if(t == numbers[j][1])
                return 1;
            
            aux.push_back(0);
            aux.push_back(numbers[j][1]-t);
            for(int k = 0;k<numbers[j][1]-t;k++)
            {
                aux.push_back(numbers[j][k+2]);   
            }
            for(t = i+1;t<numbers.size();t++)
            {
                if(t == j)
                    continue;
                if(comp2(aux,numbers[j]) == 1)
                    return 1;
            }
            return -1;
        }
        else
        {
            aux.push_back(0);
            aux.push_back(numbers[i][1]-t);
            for(int k = 0;k<numbers[i][1]-t;k++)
            {
                aux.push_back(numbers[i][k+2]);   
            }
            for(t = i+1;t<numbers.size();t++)
            {
                if(t == j)
                    continue;
                if(comp2(aux,numbers[i]) == 1)
                    return -1;
            }
            return 1;           
        }
    }
    
    vector<int> comp2(vector<int> n1, vector<int> n2)
    {
        int t;
        for(t = 0;t<n1[1] && t<n2[1];t++)
        {
            if(n1[n1[1]+1-t] < n2[n2[1]+1-t])
                return -1;
            else if(n1[n1[1]+1-t] > n2[n2[1]+1-t])
                return 1;
        }        
        return 
    }
    
    vector<int> convert(int number)
    {
        vector<int> res;
        res.push_back(number);
        res.push_back(0);
        while(number > 0)
        {
            res[1]+=1;
            res.push_back(number%10);
            number = number/10;
        }
        return res;
    }
    
    
};

// good solution

bool srt(int a,int b)
{
    string x=to_string(a);
    string y=to_string(b);
    return (x+y>y+x);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        string res="";
        if(nums.size()==0)
            return res;
        int fg=1;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0)
            { fg=0; break; }
        if(fg==1) return "0";
        sort(nums.begin(),nums.end(),srt);
        for(auto j:nums)
            res+=to_string(j);
        
        return res;
    }
};
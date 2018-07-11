class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() <= 10)
            return res;
        
        int value = 0;
        int i;
        for(i = 0;i<10;i++)
        {
            value = (value << 2) + convert(s[i]);
        }
        
        map<int,int> buffer;
        buffer.insert(pair<int,int>(value,1));
        for(;i<s.size();i++)
        {
            value = ((value << 2) + convert(s[i])) & 0xfffff;
            if(buffer.find(value) != buffer.end())
            {
                buffer[value] += 1;
            }
            else
            {
                buffer.insert(pair<int,int>(value,1));
            }
        }
        
        for(auto iter = buffer.begin();iter != buffer.end();iter++)
        {
            if(iter->second > 1)
            {
                res.push_back(convert2(iter->first));
            }
        }
        
        return res;
    }
    
    int convert(char c)
    {
        if(c == 'A')
            return 0;
        if(c == 'C')
            return 1;
        if(c == 'T')
            return 2;
        return 3;
    }
    
    string convert2(int num)
    {
        string s("");
        for(int i = 9;i>=0;i--)
        {
            int temp = (num>>(2*i))&3;
            if(temp == 0)
                s = s+'A';
            else if(temp == 1)
                s = s+'C';
            else if(temp == 2)
                s = s+'T';
            else
                s = s+'G';
        }
        return s;
    }
    
};
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(str == "")
            return (pattern == "");
        
        str = str + " ";
        int start = 0, end = 0;
        vector<string> str2;
        while(1)
        {
            end = str.find(" ",start);
            if(end == string::npos)
                break;
            str2.push_back(str.substr(start,end-start));
            start = end+1;
        }
        
        if(pattern.size() != str2.size())
            return false;

        vector<int> exist(26,0);
        unordered_map<string, char> iso;
        
        for(int i = 0;i<pattern.size();i++)
        {
            if(iso.count(str2[i]) == 1)
            {
                if(iso[str2[i]] != pattern[i])
                    return false;
            }
            else
            {
                if(exist[pattern[i]-'a'] == 1)
                    return false;
                iso[str2[i]] = pattern[i];
                exist[pattern[i]-'a'] = 1;
            }
        }
        
        return true;
    }
};
// My solution: Time Exceed Limit
class Solution {

vector<string> res;
vector<vector<int>> fig;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0)
            return res;
        
        if(!precheck(s, wordDict))
            return res;
        
        for(int i = 0;i<s.size();i++)
        {
            add_to_fig(i, wordDict, s);
        }
        
        vector<int> pre(1,0);
        travel(s, pre, 0);
        
        return res;
    }
    
    void travel(string& s, vector<int>& pre, int from)
    {
        if(from == s.size())
        {
            string temp = "";
            for(int i = 0;i < pre.size()-1;i++)
            {
                temp += s.substr(pre[i],pre[i+1]-pre[i]);
                temp += " ";
            }
            res.push_back(temp.substr(0,temp.size()-1));
        }
        else
        {
            for(int i = 0;i < fig[from].size();i++)
            {
                pre.push_back(fig[from][i]);
                travel(s, pre, fig[from][i]);
                pre.pop_back();
            }
        }
        return;
    }
    
    void add_to_fig(int i,vector<string>& wordDict, string& s)
    {
        vector<int> temp;
        for(int j = 0;j<wordDict.size();j++)
        {
            if(s.size()-i >= wordDict[j].size())
            {
                if(s.substr(i,wordDict[j].size()) == wordDict[j])
                    temp.push_back(i+wordDict[j].size());
            }
        }   
        fig.push_back(temp);
        return;
    }
    
    bool precheck(string& s, vector<string>& wordDict)
    {
        vector<int> htable(26,0);
        for(int i = 0;i<wordDict.size();i++)
        {
            for(int j = 0;j < wordDict[i].size();j++)
            {
                htable[wordDict[i][j]-'a'] = 1;
            }
        }
        
        for(int i = 0;i<s.size();i++)
        {
            if(htable[s[i]-'a'] == 0)
                return false;
        }
        return true;
    }
};

// Other's Solution
// even this large output problem, we can also cache the middle results
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
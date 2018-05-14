// other people's code
void reverseWords(string &s) {
    int start = 0;
    int e = 0;
    while(e <= s.size())
    {
        while(e < s.size() && s[e] == ' ')
        {
            s.erase(s.begin() + e);
        }
        while(e < s.size() && s[e] !=' ')
            e++;
        
        if(e <= s.size())
        {
            reverse(s.begin() + start,s.begin() + e);
            e++;
            start = e;  
        }

    }

    reverse(s.begin(),s.end());
    
    e = 0;
    while(e < s.size() && s[e] == ' ')
    {
        s.erase(s.begin() + e);
    }
}

// my code
class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        int now = 0;
        
        while(now < s.size())
        {
            start = now;
            while(now < s.size() && s[now] == ' ')
                now++;
            s.erase(s.begin()+start,s.begin()+now);
       
            now = start;
            while(now < s.size() && s[now] != ' ')
                now++;
            reverse(s.begin()+start,s.begin()+now);
            now++;
        }
        
        reverse(s.begin(),s.end());
        
        for(now = s.size()-1;now>=0;now--)
        {
            if(s[now] != ' ')
                break;
        }
        s.erase(s.begin()+now+1,s.end());
        if(s[0] == ' ')
            s.erase(s.begin());
    }
};
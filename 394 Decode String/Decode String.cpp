class Solution {
public:
    string decodeString(string s) {
        string res;
        if(s.size() == 0)
            return res;
        
        int pos = s.find('[');
        if(pos == -1)
            return s;
        
        int from = 0;
        while(s[from]<'0' || s[from]>'9')
            from++;
        res = s.substr(0,from);
        
        int pos2 = pos+1;
        int time = 1;
        while(1) {
            if(s[pos2] == '[')
                time++;
            if(s[pos2] == ']')
                time--;
            if(time == 0)
                break;
            pos2++;
        }
        string temp = decodeString(s.substr(pos+1,pos2-pos-1));
        string back = decodeString(s.substr(pos2+1,s.size()-pos2-1));
        time = stoi(s.substr(from, pos-from));
        for(int i = 0;i<time;i++) {
            res = res+temp;
        }
        res = res+back;
        return res;
    }
};
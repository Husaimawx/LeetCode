class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int p1,p2,p3,p4 = s.size()-1;
        for(p1 = 0; p1 < 3 && p1<p4; p1++)
        {
            if(stoi(s.substr(0,p1+1))<256 && (s[0]!='0'||p1 == 0))
            {
                for(p2 = p1+1; p2<p1+4&&p2<p4; p2++)
                {
                    if(stoi(s.substr(p1+1,p2-p1))<256 && (s[p1+1]!='0'||p2 == p1+1))
                    {
                        for(p3 = p2+1; p3<p2+4&&p3<p4; p3++)
                        {
                            if(p3 + 3 >= p4 && stoi(s.substr(p2+1,p3-p2))<256 && (s[p2+1]!='0'||p3 == p2+1) && stoi(s.substr(p3+1,p4-p3))<256 && (s[p3+1]!='0'||p4 == p3+1))
                            {
                                result.push_back(s.substr(0,p1+1)+"."+s.substr(p1+1,p2-p1)+"."+s.substr(p2+1,p3-p2)+"."+s.substr(p3+1,p4-p3));
                            }
                        }                    
                    }
                }   
            }
        }
        return result;
    }
};
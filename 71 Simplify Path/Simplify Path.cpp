class Solution {
public:
    string simplifyPath(string path) {
        string res = "/";
        for (int i = 1; i<path.size(); i++) {
            if (path[i - 1] == '/' && path[i] == '/')
                continue;
            if (i + 1 == path.size() && path[i] == '/' && res.size()!=0)
                continue;
            if (path[i - 1] == '/' && path[i] == '.' && i + 1 == path.size())
                continue;
            if (path[i - 1] == '/' && path[i] == '.' && i + 1 != path.size() && path[i + 1] == '/')
                i++;
            else if (path[i - 1] == '/' && path[i] == '.' && i + 1 != path.size() && path[i + 1] == '.' && (i + 2 == path.size() || (i + 2 != path.size() && path[i+2] == '/')) ) {
                i++;
                int j;
                for (j = res.size() - 2; j >= 0 && res[j] != '/'; j--);
                if (j < 0)
                    j = 0;
                res.resize(j);
            }
            else {
                res.push_back(path[i]);
            }
        }
        if(res.size() == 0)
            return "/";
        if(res[res.size()-1] == '/' && res.size() != 1)
            res.resize(res.size()-1);
        return res;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0)
            return "";

        map<char, int> M;
        int value = 0;
        for (int i = 0; i<t.size(); i++) {
            if (M.count(t[i]) == 0) {
                M[t[i]] = 0;
                value -= 1;
            } else {
                M[t[i]] -= 1;
            }
        }

        int from = 0;
        int to = 0;
        int mindis = INT_MAX;
        string res = "";
        while (to != s.size()) {
            while (1) {
                to++;
                if (M.count(s[to - 1]) != 0) {
                    M[s[to - 1]] += 1;
                    if (M[s[to - 1]] == 1)
                        value += 1;
                }
                if (value == 0) {
                    break;
                }
                if (to == s.size())
                    return res;
            }

            while (1) {
                if (M.count(s[from]) == 0) {
                    from++;
                    continue;
                }
                if (M[s[from]] != 1) {
                    M[s[from]] -= 1;
                    from++;
                }
                else {
                    break;
                }
            }

            if (mindis > to - from) {
                mindis = to - from;
                res = s.substr(from, to - from);
            }

            M[s[from]] -= 1;
            from++;
            value = -1;
        }
        return res;
    }
};
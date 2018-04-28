// My Code

class Solution {
public:
    void addResult(char a, char b, int pos, vector<int>& res)
    {
        int addnum = (int)(a - '0') * (int)(b - '0');
        int tennum = addnum / 10;
        int onenum = addnum % 10;
        res[pos] += onenum;
        res[pos + 1] += tennum;
        for (int i = pos;; i++)
        {
            if (res[i] > 9)
            {
                res[i] -= 10;
                res[i + 1] += 1;
            }
            else
            {
                if (i > pos)
                    break;
            }
        }
    }

    string multiply(string num1, string num2) {
        if (num1 == "" || num2 == "")
        {
            string ans;
            return ans;
        }
        if (num1 == "0" || num2 == "0")
        {
            string ans = "0";
            return ans;
        }
        vector<int> res(220, 0);
        int len1 = num1.length();
        int len2 = num2.length();
        for (int i = 0; i<len1; i++)
        {
            for (int j = 0; j<len2; j++)
            {
                addResult(num1[i], num2[j], len1+len2-2-i-j, res);
            }
        }

        int i;
        for (i = 219; i >= 0; i--)
        {
            if (res[i] != 0)
                break;
        }
        string ans(i + 1, '0');
        for (int j = i; j >= 0; j--)
        {
            ans[j] = (char)(res[i-j] + '0');
        }

        return ans;
    }
};


// Other people's code
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int len1 = num1.length(), len2 = num2.length();
        vector<int> temp(len1 + len2, 0);
        for (int i = 0; i < len1; ++i) {
            int d1 = num1[i] - '0';
            for (int j = 0; j < len2; ++j) {
                int d2 = num2[j] - '0';
                temp[i + j + 1] += d1 * d2;
            }
        }

        for (auto ritr = temp.rbegin(); ritr != prev(temp.rend()); ++ritr) {
            *next(ritr) += *ritr / 10;
            *ritr %= 10;
        }

        string res;
        res.reserve(temp.size());
        std::transform(temp.cbegin(), temp.cend(), back_inserter(res), [](int d) { return d + '0'; });

        int posNonzero = res.find_first_not_of('0');
        return res.substr(posNonzero);
    }
};
// Other People's Solution

class Solution {
/*
*   -Rearrange the elements(pair<first, second>) of people vector
*    in descending order of the first value, if the first value is same, 
*    in ascending order of the second value.
*   -Insert the elements(pair<first, second>) of people one by one 
*    into the linked list.
*    decrease second by one whenever find a bigger or equal first, 
*    when the second value is zero, it's the position for current pair.
*/
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans;
        if (people.size() == 0) return ans;
        sort(people.begin(), people.end(), comparePeople);
        list<pair<int, int>> ansList{{-1, 0}};
        list<pair<int, int>>::iterator iter;
        for (auto p : people) {
            int second = p.second;
            for (iter = ansList.begin(); iter != ansList.end(); iter++) {
                if (second == 0) ansList.insert(iter, p);
                if (iter->first >= p.first) second--;
            }
        }
        // [-1, 0] is the end of ansList if the people vector is a valid vector(every element can find a correct position)
        ansList.pop_back();
        for (iter = ansList.begin(); iter != ansList.end(); iter++) ans.push_back(*iter);
        return ans;
    }
    
    static bool comparePeople(pair<int, int> a, pair<int, int> b) {
        return a.first != b.first ? a.first > b.first : a.second <= b.second;
    }
};

// My Solution
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return (p1.first > p2.first) || (p1.first == p2.first && p1.second < p2.second);
        };
        
        sort(people.begin(), people.end(), comp);
        for (auto it: people) {
            res.insert(res.begin() + it.second, it);
        }
        return res;
    }
};
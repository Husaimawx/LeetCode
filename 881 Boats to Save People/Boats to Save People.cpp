class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int from = 0;
        int to = people.size()-1;
        int res = people.size();
        while(from < to) {
            while(from < to && people[from]+people[to] > limit) to--;
            if(from < to) {
                res -= 1;
                from ++;
                to--;
            }
        }
        return res;
    }
};
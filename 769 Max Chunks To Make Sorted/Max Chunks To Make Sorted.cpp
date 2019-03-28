class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() < 2)
            return arr.size();
        int from = 0;
        int count = 0;
        while(from < arr.size()) {
            int to = from;
            int i = from;
            while(i <= to) {
                to = max(to, arr[i]);
                i++;
            }
            from = i;
            count += 1;
        }
        return count;
    }
};
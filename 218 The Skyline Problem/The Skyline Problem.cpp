class Solution {
public:
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {  
    vector<pair<int,int>> height, skyline;  
    for(auto& b:buildings) {  
        height.push_back({b[0], -b[2]});  
        height.push_back({b[1], b[2]});  
    }  
    sort(height.begin(), height.end());  
    multiset<int> m;  
    int prev = 0;  
    m.insert(0);  
    for(auto& h:height) {  
        if (h.second < 0) {  
            m.insert(-h.second);  
        } else {  
            m.erase(m.find(h.second));  
        }  
        int cur = *m.rbegin();  
        if(cur != prev) {  
            skyline.push_back({h.first, cur});  
            prev = cur;  
        }  
    }  
    return skyline;  
}  
};

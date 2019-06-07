class MyCalendar {
    map<int, int> M;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(start >= end)
            return true;
        if(M.size() == 0) {
            return true;
        }
        if(M.count(start) != 0)
            return false;
        auto l = M.upper_bound(start);
        if(l == M.end() || end <= l->first) {
            if(l==M.begin() || (--l)->second <= start) {
                return true;
            }
        }
        return false;
    }
    
    void add(int start, int end) {
        M[start] = end;
        return;
    }
};

class MyCalendarTwo {
    vector<pair<int,int>> v;
    MyCalendar* obj = new MyCalendar();
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int i;
        vector<pair<int,int>> temp;
        for(i = 0;i<v.size();i++) {
            if(start >= v[i].second || v[i].first >= end)
                continue;
            if(!obj->book(max(start,v[i].first),min(end,v[i].second)))
                break;
            else
                temp.push_back(pair<int,int>(max(start,v[i].first),min(end,v[i].second)));
        }  
        if(i == v.size()) {
            v.push_back(pair<int,int>(start,end));
            for(auto item : temp) {
                obj->add(item.first,item.second);
            }
            return true;
        }
        return false;
    }
    
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
class MyCalendar {
    map<int, int> M;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(start >= end)
            return true;
        if(M.size() == 0) {
            M[start] = end;
            return true;
        }
        if(M.count(start) != 0)
            return false;
        auto l = M.upper_bound(start);
        if(l == M.end() || end <= l->first) {
            if(l==M.begin() || (--l)->second <= start) {
                M[start] = end;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
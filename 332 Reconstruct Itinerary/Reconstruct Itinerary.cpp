class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res(1,"JFK");
        if(tickets.size() == 0)
            return res;
        
        map<string,multiset<string>> data;
        
        for(int i = 0;i<tickets.size();i++) {
            if(data.count(tickets[i].first) == 0) {
                multiset<string> temp;
                temp.insert(tickets[i].second);
                data[tickets[i].first] = temp;   
            } else {
                data[tickets[i].first].insert(tickets[i].second);
            }
        }
        
        bool ans = findItineraryAux(res, tickets.size(), data);
        //cout << ans;
        return res;
    }
    
    bool findItineraryAux(vector<string>& res, int tickets,map<string,multiset<string>>& data) {
        if(tickets == 0)
            return true;
        string now = res[res.size()-1];
        //multiset<string>::iterator it;
        multiset<string> copy = data[now];
        string last = "";
        for(auto it = copy.begin();it!=copy.end();it++) {
            if(last == *it)
                continue;
            else
                last =*it;
            data[now].erase(data[now].find(*it));
            res.push_back(*it);
            //cout << *it << endl;
            if(findItineraryAux(res,tickets-1, data))
                return true;
            res.pop_back();
            data[now].insert(*it);
        }
        return false;
    }
};
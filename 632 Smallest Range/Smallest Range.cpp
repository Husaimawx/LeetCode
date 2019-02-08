class Solution {
public:
vector<int> smallestRange(vector<vector<int>>& nums) {
  vector<int> res(2, 0);
  int dis = INT_MAX;
  multiset<int> S;
  vector<int> pos(nums.size(), 0);
  map<int, vector<int>> M;

  for (int i = 0; i<nums.size(); i++) {
    S.insert(nums[i][0]);
    if (M.count(nums[i][0]) == 0) {
      vector<int> temp;
      M[nums[i][0]] = temp;
    }
    M[nums[i][0]].push_back(i);
  }
  if (dis >(*(S.rbegin()) - *(S.begin()))) {
    dis = (*(S.rbegin()) - *(S.begin()));
    res[0] = *(S.begin());
    res[1] = *(S.rbegin());
  }
  while (1) {
    int temp = *(S.begin());
    S.erase(temp);
    for (int i = 0; i<M[temp].size(); i++) {
            
            int t = 1;
            while(pos[M[temp][i]]+t != nums[M[temp][i]].size() && nums[M[temp][i]][pos[M[temp][i]]+t] == nums[M[temp][i]][pos[M[temp][i]]])
                t++;
                
            pos[M[temp][i]] += t;    
                
      if (pos[M[temp][i]] == nums[M[temp][i]].size())
        return res;
      S.insert(nums[M[temp][i]][pos[M[temp][i]]]);
      M[nums[M[temp][i]][pos[M[temp][i]]]].push_back(M[temp][i]);
    }
    if (dis >(*(S.rbegin()) - *(S.begin()))) {
      dis = (*(S.rbegin()) - *(S.begin()));
      res[0] = *(S.begin());
      res[1] = *(S.rbegin());
    }
  }

}
};
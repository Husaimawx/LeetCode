// other's solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};

// my solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
        {
            if(nums[0] == k)
                return 1;
            else
                return 0;
        }
        
        int res = 0;
        int n = nums.size()/2;
        
        vector<int> part1(nums.begin(),nums.begin()+n);
        int res1 = subarraySum(part1,k);
        res += res1;
        
        vector<int> part2(nums.begin()+n,nums.end());
        int res2 = subarraySum(part2,k);
        res += res2;
        
        vector<int> l;
        int start = 0;
        for(int i = n-1;i>=0;i--)
        {
            start+=nums[i];
            l.push_back(start);
        }
        
        vector<int> r;
        start = 0;
        for(int i = n;i<nums.size();i++)
        {
            start+=nums[i];
            r.push_back(start);
        }
        
        sort(l.begin(), l.end());
        sort(r.begin(),r.end());
        
        vector<pair<int,int>> left;
        left.push_back(make_pair(l[0],1));
        for(int i = 1;i<l.size();i++)
        {
            if(l[i] == l[i-1])
            {
                left[left.size()-1].second += 1;
            }
            else
            {
                left.push_back(make_pair(l[i],1));
            }
        }
        
        vector<pair<int,int>> right;
        right.push_back(make_pair(r[0],1));
        for(int i = 1;i<r.size();i++)
        {
            if(r[i] == r[i-1])
            {
                right[right.size()-1].second += 1;
            }
            else
            {
                right.push_back(make_pair(r[i],1));
            }
        }
        
        int from = 0;
        int to = right.size()-1;
        
        while(1)
        {
            if(left[from].first+right[to].first == k)
            {
                res+=left[from].second*right[to].second;
                from++;
                to--;
            }
            else if(left[from].first+right[to].first < k)
            {
                from++;
            }
            else
            {
                to--;
            }
            if(from >= left.size() || to < 0)
                break;
        }
        
        return res;
    }
};
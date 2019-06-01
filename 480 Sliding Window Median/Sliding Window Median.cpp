class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& num2, int k) {
        vector<double> nums(num2.size());
        for(int i = 0;i<num2.size();i++) {
            nums[i] = double(num2[i]) + 0.2/(double(i)+1);
        }
        vector<double> res;
        if(k == 1) {
            for(int i = 0;i<nums.size();i++) {
                res.push_back(floor(nums[i]));
            }
            return res;
        }
        
        int left = k/2;
        int right = k-k/2;
        
        priority_queue<double> small;
        priority_queue<double,vector<double>,greater<double>> big;
        
        vector<double> temp(nums.begin(), nums.begin()+k);
        sort(temp.begin(),temp.end());
        for(int i = 0;i<left;i++) {
            small.push(temp[i]);
        }
        for(int i = left;i<k;i++) {
            big.push(temp[i]);
        }
        
        
        unordered_map<double,int> M;
        
        for(int i = k;i<=nums.size();i++) {
            while(!empty(small)) {
                if(M[small.top()] != 0) {
                    M[small.top()] -= 1;
                    small.pop();
                } else {
                    break;
                }             
            }
            while(!empty(big)) {
                if(M[big.top()] != 0) {
                    M[big.top()] -= 1;
                    big.pop();
                } else {
                    break;
                }             
            }
            
            //cout << small.top() << ' ' << big.top() << endl;
            
            if(k % 2 == 0) {
                res.push_back((double(floor(big.top()))+double(floor(small.top())))/2);    
            } else {
                res.push_back(floor(big.top()));
            }          
            
            if(i == nums.size())
                break;
            
            double flag = big.top();
            int tf = left;
            int tr = right;
            M[nums[i-k]] += 1;
            if(nums[i-k] < flag) {
                tf -= 1;
            } else {
                tr -= 1;
            }
            if(nums[i] < flag) {
                small.push(nums[i]);
                tf += 1;
            } else {
                big.push(nums[i]);
                tr += 1;
            }
            
            if(tf == left-1) {
                small.push(big.top());
                big.pop();
                //cout << "f" << endl;
            } else if(tf == left+1) {
                big.push(small.top());
                small.pop();
                //cout << "c" << endl;
            }
        }

        return res;
    }
    
};
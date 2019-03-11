class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<long> lnum(nums.size()-k+1, 0);
        for(int i = 0;i<k;i++) {
            lnum[0] += nums[i];
        }
        for(int i = 1;i<lnum.size();i++) {
            lnum[i] = lnum[i-1]-nums[i-1]+nums[i-1+k];
        }
        
        vector<long> first(lnum.size(),lnum[lnum.size()-1]);
        vector<int> first_pos(lnum.size(), lnum.size()-1);
        for(int i = int(lnum.size())-2;i>=0;i--) {
            if(first[i+1] > lnum[i]) {
                first[i] = first[i+1];
                first_pos[i] = first_pos[i+1];
            }
            else {
                first[i] = lnum[i];
                first_pos[i] = i;
            }
        }
        
        //for(int i = 0;i<first.size();i++)
        //    cout << first[i];
        //cout << endl;
        
        vector<long> second(lnum.size()-k, lnum[lnum.size()-1]+lnum[lnum.size()-k-1]);
        vector<long> second_pos(lnum.size()-k, second.size()-1);
        for(int i = int(second.size())-2;i>=0;i--) {
            if(second[i+1] > lnum[i]+first[i+k]) {
                second[i] = second[i+1];
                second_pos[i] = second_pos[i+1];
            } else {
                second[i] = lnum[i]+first[i+k];
                second_pos[i] = i;
            }
        }
        
        //for(int i = 0;i<second.size();i++)
        //    cout << second[i];
        //cout << endl;
        
        vector<long> third(second.size()-k, lnum[second.size()-k-1]+second[second.size()-1]);
        vector<long> third_pos(second.size()-k, third.size()-1);
        for(int i = int(third.size())-2;i>=0;i--) {
            if(third[i+1] > lnum[i]+second[i+k]) {
                third[i] = third[i+1];
                third_pos[i] = third_pos[i+1];
            } else {
                third[i] = lnum[i]+second[i+k];
                third_pos[i] = i;
            }        
        }
        
        //for(int i = 0;i<third.size();i++)
        //    cout << third[i];
        //cout << endl;
        
        vector<int> res({third_pos[0], second_pos[third_pos[0]+k], first_pos[second_pos[third_pos[0]+k]+k]});
        return res;
    }
};
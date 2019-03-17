class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size() == 0)
            return asteroids;
        
        vector<int> res(asteroids.size(),0);
        stack<int> st1;
        int i;
        for(i = 0;i < asteroids.size();i++) {
            if(asteroids[i] > 0) {
                st1.push(i);
                break;
            }
        }
        if(i == asteroids.size())
            return asteroids;
        
        for(int j = i+1;j<asteroids.size();j++) {
            if(asteroids[j] > 0) {
                st1.push(j);
            } else {
                while(st1.size() != 0 && asteroids[st1.top()] <= abs(asteroids[j])) {
                    if(asteroids[st1.top()] == abs(asteroids[j]))   {
                        st1.pop();
                        break;    
                    }
                    st1.pop();
                }
            }
        }
        
        stack<int> st2;
        for(i = asteroids.size()-1;i >=0;i--) {
            if(asteroids[i] < 0) {
                st2.push(i);
                break;
            }
        }
        
        if(i == -1)
            return asteroids;
        
        for(int j = i-1;j>=0;j--) {
            if(asteroids[j] < 0) {
                st2.push(j);
            } else {
                while(st2.size() != 0 && abs(asteroids[st2.top()]) <= asteroids[j]) {
                    if(abs(asteroids[st2.top()]) == asteroids[j]) {
                        st2.pop();
                        break;
                    }
                    st2.pop();
                }
            }
        }       
        
        while(st1.size() != 0) {
            res[st1.top()] = 1;
            st1.pop();
        }
        
        while(st2.size() != 0) {
            res[st2.top()] = 1;
            st2.pop();
        }
        
        vector<int> ans;
        for(int i = 0;i<asteroids.size();i++) {
            if(res[i] != 0)
                ans.push_back(asteroids[i]);
        }
        return ans;
    }
};
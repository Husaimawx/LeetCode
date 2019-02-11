class Solution {
public:
    unordered_map<int, int> M;
    int bit;
    
public:
    int shoppingOffersAux(vector<int>& price, vector<vector<int>>& special,vector<int>& specialvalue, int key) {
        //cout << key << "fuck" << endl;
        if(M.count(key) != 0)
            return M[key];
        
        vector<int> needs(bit,0);
        int k2 = key;
        int l = bit-1;
        while(k2 != 0) {
            needs[l] = k2%10;
            k2 /= 10;
            l--;
        }
        
        //for(int i = 0;i<needs.size();i++)
        //    cout << needs[i];
        //cout << endl;
        
        int res = 0;
        int temp = 1;
        for(int i = 0;i<price.size();i++) {
            res += price[i]*needs[i];
        }
    
        
        for(int i = 0;i<special.size();i++) {
            int flag = 1;
            for(int j = 0;j<needs.size();j++) {
                if(needs[j] < special[i][j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                if(key < specialvalue[i])
                    cout << key << " " << specialvalue[i] << endl;
                res = min(res,special[i][needs.size()] + shoppingOffersAux(price, special,specialvalue, key-specialvalue[i]));
            }
        }
        
        M[key] = res;
        return res;
    }
    
    int get_key(vector<int>& v) {
        int res = 0;
        for(int i = 0;i<v.size();i++) {
            res = res*10 + v[i];
        }
        return res;
    }
    
    int get_key2(vector<int>& v) {
        int res = 0;
        for(int i = 0;i+1<v.size();i++) {
            res = res*10 + v[i];
        }
        return res;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        M[0] = 0;
        vector<int> specialvalue;
        for(int i = 0;i<special.size();i++)
            specialvalue.push_back(get_key2(special[i]));
        //cout << specialvalue[0] << specialvalue[1];
        bit = needs.size();
        return shoppingOffersAux(price, special,specialvalue, get_key(needs));
    }
};
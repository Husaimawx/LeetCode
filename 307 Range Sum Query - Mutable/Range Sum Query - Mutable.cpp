class NumArray {
public:
    int n;
    vector<int> tree;
    
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        tree.resize(2*n);
        for(int i = 0;i<n;i++) {
            tree[n+i] = nums[i];
        }
        for(int i = n-1;i>0;i--) {
            tree[i] = tree[i*2]+tree[i*2+1];   
        }
    }
    
    void update(int i, int val) {
        int m = n+i;
        int dis = val-tree[m];
        while(1) {
            tree[m] += dis;
            m /= 2;
            if(m == 0)
                break;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        i += n;
        j += n;
        while(i < j) {
            if(i % 2 == 1) {
                sum += tree[i];
                i++;
            }
            if(j % 2 == 0) {
                sum += tree[j];
                j--;
            }       
            i = i/2;
            j = j/2;
        }
        if(i == j)
            sum += tree[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0 && n == 0)
            return;
        
        int i;
        for(i = m+n-1;i>=0;i--)
        {
            if(m == 0 || n == 0)
                break;
            if(nums1[m-1]<nums2[n-1])
            {
                nums1[i] = nums2[n-1];
                n--;
            }
            else
            {
                nums1[i] = nums1[m-1];
                m--;               
            }
        }
        if(m == 0)
        {
            while(n>0)
            {
                nums1[n-1] = nums2[n-1];
                n--;
            }
        }
        return;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int min = 0, max = n-k;
        int res;
        while(min <= max)
        {
            int mid = (min+max)/2;
            if(mid !=0 && ((abs(arr[mid-1]-x)<abs(arr[mid+k-1]-x))||(abs(arr[mid-1]-x)==abs(arr[mid+k-1]-x) && arr[mid+k-1]>x)))
                max = mid-1;
            else if(mid != n-k && (abs(arr[mid]-x)>abs(arr[mid+k]-x) || (abs(arr[mid]-x)==abs(arr[mid+k]-x) && arr[mid+k]<x)))
                min = mid+1;
            else
            {
                res = mid;
                break;
            }
        }
        if(min == max)
            res = min;
        vector<int> ans;
        for(int i = 0;i<k;i++)
        {
            ans.push_back(arr[res+i]);
        }
        return ans;
    }
};
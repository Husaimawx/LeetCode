// other people's solution
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            //cout<<mid<<' '<<nums[mid]<<endl;
            if(nums[mid] == target) 
                return true;
            else if(nums[i] == nums[mid])i++;//如果左段左右两边相等，无法判断哪一段有序
            else if(nums[i] < nums[mid]){//左边有序
                if(nums[i] <= target && target < nums[mid]) //如果目标数在有序范围内
                    j = mid-1;
                else
                    i = mid + 1;
            }else {//左边无序，即右边有序
                if(nums[mid] < target && target <= nums[j] ) //如果目标数在右边有序范围内
                    i = mid +1;
                else 
                    j = mid-1;
            }
        }
        return false;
    }
};

// my solution
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        
        int temp;
        int from = 0, to = nums.size()-1;
        while(from <= to)
        {
            if(nums[from] < nums[to])
                return binarySearch(nums, target, from, to);
            else if(nums[from] == nums[to])
            {
                if(nums[from] == target)
                    return true;
                from++;
            }
            else
            {
                temp = (from+to)/2;
                if(nums[temp] == target)
                    return true;
                if(nums[temp]>=nums[from])
                {
                    if(binarySearch(nums, target, from, temp-1))
                        return true;
                    from = temp+1;
                }
                else
                {
                    if(binarySearch(nums, target, temp+1, to))
                        return true;
                    to = temp-1;
                }
            }          
        }
        return false;
    }
    
    bool binarySearch(vector<int>& nums, int target, int from, int to)
    {
        int temp;
        while(from <=to)
        {
            temp = (from+to)/2;
            if(nums[temp] == target)
                return true;
            else if(nums[temp] < target)
                from = temp+1;
            else
                to = temp-1;
        }
        return false;
    }
};
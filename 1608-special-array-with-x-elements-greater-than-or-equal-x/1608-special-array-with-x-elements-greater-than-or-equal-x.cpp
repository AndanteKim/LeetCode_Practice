class Solution {
private:
    int n;
    int getFirstGreaterOrEqual(vector<int>& nums, int val){
        int start = 0, end = n - 1, i = n;
        
        while (start <= end){
            int mid = (start + end) >> 1;
            
            if (nums[mid] >= val){
                i = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return i;
    }
    
public:
    int specialArray(vector<int>& nums) {
        this -> n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i <= n; ++i){
            int k = getFirstGreaterOrEqual(nums, i);
            if (n - k == i)
                return i;
        }
        
        return -1;
    }
};
class Solution {
private:
    int n;
    
    int binarySearch(vector<int>& nums, int startIndex, int target){
        int left = startIndex, right = n - 1;
        
        while (left < right){
            int mid = (left + right + 1) >> 1;
            if (nums[mid] < target) left = mid;
            else right = mid - 1;
        }
        
        return left;
    }
    
    int twoSumSmaller(vector<int>& nums, int startIndex, int target){
        int sum = 0;
        for (int i = startIndex; i < n - 1; ++i){
            int j = binarySearch(nums, i, target - nums[i]);
            sum += j - i;
        }
        
        return sum;
    }
    
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i)
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        
        return ans;
    }
};
class Solution {
private:
    int n;
    int twoSumSmaller(vector<int>& nums, int startIndex, int target){
        int sum = 0, left = startIndex, right = n - 1;
        while (left < right){
            if (nums[left] + nums[right] < target){
                sum += right - left;
                ++left;
            }
            else --right;
        }
        
        return sum;
    }
    
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n - 2; ++i)
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        
        return ans;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        
        // Use cycle sort to place positive elements smaller than n
        // at the nums[i] - 1
        while (i < n){
            if (0 < nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                ++i;
        }
        
        // Iterate through nums
        // return the smallest missing positive integer
        for (int i = 0; i < n; ++i){
            if (nums[i] != i + 1) return i + 1;
        }
        
        // If all elements at the correctIndex
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};
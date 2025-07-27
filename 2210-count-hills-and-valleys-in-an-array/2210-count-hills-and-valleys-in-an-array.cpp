class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, n = nums.size(), i = 1;
        int j, k;
        
        while (i < n - 1){
            j = i - 1, k = i + 1;

            while (k < n - 1 && nums[i] == nums[k]) ++k;

            // Hill
            if (nums[j] < nums[i] && nums[i] > nums[k]) ++ans;
            else if (nums[i] < nums[j] && nums[k] > nums[i]) ++ans;
            
            i = k;
        }

        return ans;
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // Base case
        if (n <= 1) return true;

        int inversion = 0;
        // For every pair, count the number of inversions
        for (int i = 1; i < n; ++i){
            if (nums[i - 1] > nums[i]) ++inversion;
        }
        
        // Also, check between the first and last element due to the rotation
        if (nums[0] < nums[n - 1]) ++inversion;

        return inversion <= 1;
    }
};
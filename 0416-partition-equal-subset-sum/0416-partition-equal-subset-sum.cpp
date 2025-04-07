class Solution {
private:
    int n;
    bool dp(int i, int subsetSum, vector<int>& nums, vector<vector<int>>& memo){
        // Base cases: If subsetSum is splitted
        if (subsetSum == 0) return true;

        if (subsetSum < 0 || i == 0) return false;

        // Check if subsetSum for given n is already computed and stored in memo
        if (memo[i][subsetSum] != -1) return memo[i][subsetSum];

        return memo[i][subsetSum] = dp(i - 1, subsetSum - nums[i], nums, memo) || dp(i - 1, subsetSum, nums, memo);
    }

public:
    bool canPartition(vector<int>& nums) {
        this -> n = nums.size();

        // Find the sum of all array elements
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        
        int subsetSum = totalSum >> 1;
        vector memo(n + 1, vector<int>(subsetSum + 1, -1));

        return dp(n - 1, subsetSum, nums, memo);
    }
};
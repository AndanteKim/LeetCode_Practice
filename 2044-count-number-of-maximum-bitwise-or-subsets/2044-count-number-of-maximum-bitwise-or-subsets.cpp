class Solution {
private:
    int n;
    
    int backtrack(int i, int currOr, int maxOr, vector<int>& nums, vector<vector<int>>& memo){
        // Base case: Reached the end of the array
        if (i == n) return (currOr == maxOr)? 1 : 0;
        
        // Check if the result for this state is already memoized
        if (memo[i][currOr] != -1) return memo[i][currOr];
        
        // Don't include the current number
        int countWithout = backtrack(i + 1, currOr, maxOr, nums, memo);
        
        // Include the current number
        int countWith = backtrack(i + 1, currOr | nums[i], maxOr, nums, memo);
        
        // Memoize and return the result
        return memo[i][currOr] = countWithout + countWith;
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this -> n = nums.size();
        
        int maxOrVal = 0;
        
        // Calculate the maximum OR value
        for (int num : nums) maxOrVal |= num;
        
        vector memo(n, vector<int>(maxOrVal + 1, -1));
        return backtrack(0, 0, maxOrVal, nums, memo);
    }
};
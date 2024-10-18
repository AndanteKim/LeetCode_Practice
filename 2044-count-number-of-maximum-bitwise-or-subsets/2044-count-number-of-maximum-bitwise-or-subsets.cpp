class Solution {
private:
    int n;
    int backtrack(int i, int currOr, int targetOr, vector<int>& nums){
        // Base case: Reached the end of the array
        if (i == n) return (currOr == targetOr)? 1 : 0;
        
        // Don't include the current number
        int countWithout = backtrack(i + 1, currOr, targetOr, nums);
        
        // Include the current number
        int countWith = backtrack(i + 1, currOr | nums[i], targetOr, nums);
        
        // Return the sum of both cases
        return countWithout + countWith;
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this -> n = nums.size();
        int maxOrValue = 0;
        for (int num : nums) maxOrValue |= num;
        return backtrack(0, 0, maxOrValue, nums);
    }
};
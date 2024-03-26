class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // look up
        vector<bool> seen(n + 1);
        
        // Mark the elements from nums in the lookup array
        for (int num:nums){
            if (0 < num && num <= n)
                seen[num] = true;
        }
        
        // Iterate through integers 1 to n
        // return smallest missing positive integer
        for (int i = 1; i <= n; ++i)
            if (!seen[i]) return i;
        
        // If seen contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};
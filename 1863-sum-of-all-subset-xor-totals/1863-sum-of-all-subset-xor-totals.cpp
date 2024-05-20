class Solution {
private:
    int n;
    int generateSubsets(vector<int>& nums, int i, int currXor){
        // Return the sum of subsets when all elements are already considered
        if (i == n)
            return currXor;
        
        // Calculate sum of subset with current element
        int withElement = generateSubsets(nums, i + 1, currXor ^ nums[i]);
        
        // Calculate sum of subset without current element
        int withoutElement = generateSubsets(nums, i + 1, currXor);
        
        // Return sum of xor totals
        return withElement + withoutElement;
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        this -> n = nums.size();
        return generateSubsets(nums, 0, 0);
    }
};
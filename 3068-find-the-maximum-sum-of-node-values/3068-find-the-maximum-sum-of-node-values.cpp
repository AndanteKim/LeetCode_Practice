class Solution {
private:
    int n, k;
    long long maxSumOfNodes(int i, int isEven, vector<int>& nums, vector<vector<long long>>& memo){
        if (i == n)
            // If the operation is performed on an odd number of elements retuurn INT_MIN
            return isEven? 0 : INT_MIN;
        
        if (memo[i][isEven] != -1)
            return memo[i][isEven];
            
        // No operation is performed on the element
        long long noXorDone = nums[i] + maxSumOfNodes(i + 1, isEven, nums, memo);
        
        // Operation is performed on the element
        long long xorDone = (nums[i] ^ k) + maxSumOfNodes(i + 1, isEven ^ 1, nums, memo);
            
        // Memoize the maximum of result
        return memo[i][isEven] = max(noXorDone, xorDone);
    }
    
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        this -> n = nums.size(), this -> k = k;
        vector<vector<long long>> memo(n, vector<long long>(2, -1));
        
        return maxSumOfNodes(0, 1, nums, memo);
    }
};
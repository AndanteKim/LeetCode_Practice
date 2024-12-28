class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        this -> k = k;
        // Number of possible subarray starting positions
        int n = nums.size() - k + 1;
        
        // Calculate sum of all possible k-length subarrays
        vector<int> sums(n);
        sums[0] = accumulate(nums.begin(), nums.begin() + k, 0);

        // Sliding window to calculate remaining sums
        for (int i = k; i < nums.size(); ++i){
            sums[i - k + 1] = sums[i - k] - nums[i - k] + nums[i];
        }
        // memo[i][j]: max sum possible starting from index i with j subarrays remaining
        vector memo(n, vector<int>(4, -1));
        
        // First find optimal sum using DP
        dp(sums, 0, 3, memo);
        
        // Then, reconstruct the path to find indices
        vector<int> indices;
        dfs(sums, 0, 3, memo, indices);

        return indices;
    }

private:
    int k;

    // DP function to find maximum possible sum
    int dp(vector<int>& sums, int idx, int rem, vector<vector<int>>& memo){
        // Base case 1
        if (rem == 0) return 0;

        // Base case 2
        if (idx >= sums.size())
            return (rem > 0)? std::numeric_limits<int>::min() : 0;

        // Base case 3
        if (memo[idx][rem] != -1)
            return memo[idx][rem];

        // Try taking current subarray vs skipping it
        int withCurr = sums[idx] + dp(sums, idx + k, rem - 1, memo);
        int skipCurr = dp(sums, idx + 1, rem, memo);

        return memo[idx][rem] = max(withCurr, skipCurr);
    }
    
    // DFS to reconstruct the solution path
    void dfs(vector<int>& sums, int idx, int rem, vector<vector<int>>& memo, vector<int>& indices){
        if (rem == 0 || idx >= sums.size()) return;

        int withCurr = sums[idx] + dp(sums, idx + k, rem - 1, memo);
        int skipCurr = dp(sums, idx + 1, rem, memo);

        // Choose path giving optimal resutl in DP
        if (withCurr >= skipCurr){  // Take current subarray
            indices.push_back(idx);
            dfs(sums, idx + k, rem - 1, memo, indices);
        }
        else    // Skip current subarray
            dfs(sums, idx + 1, rem, memo, indices);
    }
};
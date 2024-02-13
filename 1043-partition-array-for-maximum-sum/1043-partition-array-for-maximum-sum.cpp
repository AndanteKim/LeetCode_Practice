class Solution {
private:
    int n;
    int dp(int start, int k, int memo[], vector<int>& arr){
        if (start >= n)
            return 0;
        
        // Return the already calculated answer
        if (memo[start] != -1)
            return memo[start];
        
        int currMax = 0, ans = 0;
        int end = min(n, start + k);
        for (int i = start; i < end; ++i){
            currMax = max(currMax, arr[i]);
            // Store the maximum of all options for the current subarray
            ans = max(ans, currMax * (i - start + 1) + dp(i + 1, k, memo, arr));
        }
        
        // Store the answer to be reused
        return memo[start] = ans;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this -> n = arr.size();
        int memo[n];
        memset(memo, -1, sizeof(memo));
        
        return dp(0, k, memo, arr);
    }
};
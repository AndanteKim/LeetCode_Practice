class Solution {
private:
    int n;
    int solve(int b, int w, vector<vector<int>>& dp, vector<int>& blocks, int split){
        // base case
        if (b == n) return 0;
        if (w == 0) return 1e9;
        if (w >= n - b) return blocks[b];
        
        // If the subproblem is already solved, return result
        if (dp[b][w] != -1) return dp[b][w];
        
        // 2 choices
        int workHere = max(blocks[b], solve(b + 1, w - 1, dp, blocks, split));
        int splitHere = split + solve(b, min(2 * w, n - b), dp, blocks, split);
        
        // store the result in dp array
        dp[b][w] = min(workHere, splitHere);
        return dp[b][w];
    }
    
public:
    int minBuildTime(vector<int>& blocks, int split) {
        this -> n = blocks.size();
        
        // sort the blocks in descending order
        sort(blocks.begin(), blocks.end(), [](int a, int b){return a > b;});
        
        // dp[i][j] represents the time taken
        // build blocks[i ~ n - 1] blocks using j workers
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        // For block from index 0, with 1 worker
        return solve(0, 1, dp, blocks, split);
    }
};
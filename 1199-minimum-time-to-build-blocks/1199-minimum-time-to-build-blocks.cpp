class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        // sort the blocks in descending order
        int N = blocks.size();
        sort(blocks.begin(), blocks.end(), [](int a, int b){return a > b;});
        
        // Initialize the array
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        
        // base case 1: If there are no workers, we can't build any block
        for (int b = 0; b < N; ++b) dp[b][0] = INT_MAX;
        
        // base case 2: If there are no blocks, we don't need any time
        for (int w = 0; w <= N; ++w) dp[N][w] = 0;
        
        // fill the array in a bottom-up fashion
        for (int b = N - 1; b >= 0; --b){
            for (int w = N; w >= 1; --w){
                if (w >= N - b){
                    dp[b][w] = blocks[b];
                    continue;
                }
                
                // recur relation
                int workHere = max(blocks[b], dp[b + 1][w - 1]);
                int splitHere = split + dp[b][min(2 * w, N - b)];
                dp[b][w] = min(workHere, splitHere);
            }
        }
        
        // For building all the blocks with initially 1 worker
        return dp[0][1];
    }
};
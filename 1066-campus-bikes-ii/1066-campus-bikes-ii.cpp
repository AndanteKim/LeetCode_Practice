class Solution {
private:
    // Maximum value of mask will be 2 ^ (Number of bikes)
    // And number of bikes can be 10 at max
    int memo[1024];
    
    // Manhattan Distance
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    // 
    int minDistSum(vector<vector<int>>& workers, vector<vector<int>>& bikes, int workerIdx, int mask){
        if (workerIdx >= workers.size())
            return 0;
        
        // If result is already calculated, return it no recursion needed
        if (memo[mask] != -1)
            return memo[mask];
        
        int smallestDistSum = INT_MAX;
        for (int bikeIdx = 0; bikeIdx < bikes.size(); ++bikeIdx){
            // Check if the bike at bikeIndex is available
            if ((mask & (1 << bikeIdx)) == 0)
                // Adding the current distance and repeat the process for next worker
                // also changing the bit at index bikeIndex to 1 to show the bike there is assigned
                smallestDistSum = min(smallestDistSum, findDistance(workers[workerIdx], bikes[bikeIdx]) + minDistSum(workers, bikes, workerIdx + 1, mask | (1 << bikeIdx)));
        }
        
        // Memoizing the result corresponding to mask
        return memo[mask] = smallestDistSum;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // Marking all postions to -1 that signifies result has not been calculated yet for this week
        memset(memo, -1, sizeof(memo));
        
        return minDistSum(workers, bikes, 0, 0);
    }
};
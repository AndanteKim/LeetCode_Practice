class Solution {
private:
    int dp[1024];
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    int countNumOfOnes(int mask){
        int count = 0;
        while (mask != 0){
            mask &= (mask - 1);
            ++count;
        }
        return count;
    }
    
    int minDistSum(vector<vector<int>>& workers, vector<vector<int>>& bikes){
        /*int m = bikes.size(), n = workers.size(), smallestDistSum = INT_MAX;
        dp[0] = 0;
        
        for (int mask = 0; mask < (1 << m); ++mask){
            int nextWorkerIndex = countNumOfOnes(mask);
            if (nextWorkerIndex >= n){
                smallestDistSum = min(smallestDistSum, dp[mask]);
                continue;
            }
            for (int bikeIndex = 0; bikeIndex < m; ++bikeIndex){
                if ((mask & (1 << bikeIndex)) == 0){
                    int newMask = 1 << bikeIndex | mask;
                    dp[newMask] = min(dp[newMask], dp[mask] + findDistance(workers[nextWorkerIndex], bikes[bikeIndex]));
                }
            }
            
        }
        
        return smallestDistSum;*/
        int numOfBikes = bikes.size();
        int numOfWorkers = workers.size();
        int smallestDistanceSum = INT_MAX;

        // 0 signifies that no bike has been assigned and
        // Distance sum for not assigning any bike is equal to 0
        dp[0] = 0;
        // Traverse over all the possible values of mask
        for (int mask = 0; mask < (1 << numOfBikes); mask++) {
            int nextWorkerIndex = countNumOfOnes(mask);
            
            // If mask has more number of 1's than the number of workers
            // Then we can update our answer accordingly
            if (nextWorkerIndex >= numOfWorkers) {
                smallestDistanceSum = min(smallestDistanceSum, dp[mask]);
                continue;
            }
            
            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has already been assigned
                if ((mask & (1 << bikeIndex)) == 0) {
                    int newMask = (1 << bikeIndex) | mask;
                    
                    // Updating the distance sum for newMask
                    dp[newMask] = min(dp[newMask], dp[mask] + 
                                        findDistance(workers[nextWorkerIndex], bikes[bikeIndex]));
                }
            }
        }
        
        return smallestDistanceSum;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        for (int i = 0; i < 1024; ++i)
            dp[i] = INT_MAX;
       
        return minDistSum(workers, bikes);
    }
};
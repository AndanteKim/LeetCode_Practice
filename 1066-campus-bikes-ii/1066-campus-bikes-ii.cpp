class Solution {
private:
    // Maximum number of bikes is 10
    int smallestDistSum = INT_MAX;
    int visited[10];
    
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    void minDistSum(vector<vector<int>>& workers, int workerIdx, vector<vector<int>>& bikes, int currDistSum){
        if (workerIdx >= workers.size()){
            smallestDistSum = min(smallestDistSum, currDistSum);
            return;
        }
        
        // If the current distance sum is greater than the smallest result
        // found then stop exploring this combination of workers and bikes
        if (currDistSum >= smallestDistSum)
            return;
        
        for (int bikeIdx = 0; bikeIdx < bikes.size(); ++bikeIdx){
            // If bike is available
            if (!visited[bikeIdx]){
                visited[bikeIdx] = true;
                minDistSum(workers, workerIdx + 1, bikes, currDistSum + findDistance(workers[workerIdx], bikes[bikeIdx]));
                visited[bikeIdx] = false;
            }
        }
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        minDistSum(workers, 0, bikes, 0);
        return smallestDistSum;
    }
};
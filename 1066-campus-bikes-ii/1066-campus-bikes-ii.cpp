class Solution {
private:
    // Maximum number of bikes is 10
    int m, n, ans = std::numeric_limits<int>::max();
    int visited[10];

    // Manhattan distance
    int findDist(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    void findMinDist(vector<vector<int>>& workers, int workerIndex, vector<vector<int>>& bikes, int currDist){
        if (workerIndex == m) {
            ans = min(ans, currDist);
            return;
        }
        
        // If the curretn distance sum is greater than the smallest result
        // found then stop exploring this combination of workers and bikes
        if (currDist >= ans) return;

        for (int bikeIndex = 0; bikeIndex < n; ++bikeIndex){
            // If bike is available
            if (!visited[bikeIndex]){
                visited[bikeIndex] = 1;
                findMinDist(workers, workerIndex + 1, bikes, currDist + findDist(workers[workerIndex], bikes[bikeIndex]));
                visited[bikeIndex] = 0;
            }
        }
    }

public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        this -> m = workers.size(), this -> n = bikes.size();
        findMinDist(workers, 0, bikes, 0);
        return ans;
    }
};
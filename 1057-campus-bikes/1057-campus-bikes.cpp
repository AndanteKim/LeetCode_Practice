class Solution {
private:
    // manhattan distance function
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // store the list of (worker, bike) pairs corresponding to its distance
        vector<pair<int, int>> buckets[1999];
        int minDistance = INT_MAX;
        
        // add the (worker, bike) pairs corresponding to their distance list
        for (int i = 0; i < workers.size(); ++i){
            for (int j = 0; j < bikes.size(); ++j){
                int distance = findDistance(workers[i], bikes[j]);
                buckets[distance].push_back({i, j});
                minDistance = min(minDistance, distance);
            }
        }
        
        
        int currDistance = minDistance, pairCount = 0;
        // Initialize all values to false, to signify no bikes have been taken
        vector<bool> bikeStatus(bikes.size());
        // Initialize all index to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        
        // Until all workers have not been assigned a bike
        while (pairCount < workers.size()){
            for (auto& [worker, bike] : buckets[currDistance]){
                if (!bikeStatus[bike] && workerStatus[worker] == -1){
                    // If both worker and bike are free, assign them to each other
                    bikeStatus[bike] = true;
                    workerStatus[worker] = bike;
                    ++pairCount;
                }
            }
            ++currDistance;
        }
        
        return workerStatus;
    }
};
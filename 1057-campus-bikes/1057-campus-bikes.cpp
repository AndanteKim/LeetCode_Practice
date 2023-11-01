class Solution {
private:
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // List of triplets (distance, worker index, bike index) for each worker-bike combination
        vector<vector<tuple<int, int, int>>> workerToBikeList;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        for (int i = 0; i < workers.size(); ++i){
            vector<tuple<int, int, int>> currWorkerPairs;
            for (int j = 0; j < bikes.size(); ++j){
                int distance = findDistance(workers[i], bikes[j]);
                currWorkerPairs.push_back({distance, i, j});
            }
            // sort the workerToBikeList for the current worker in reverse order
            sort(currWorkerPairs.begin(), currWorkerPairs.end(), greater<tuple<int, int, int>>());
            
            // add the closest bike for this worker to the priority queue
            pq.push(currWorkerPairs.back());
            
            // second last is now the closest bike for this worker
            currWorkerPairs.pop_back();
            // store the remaining options for the current worker in workerToBikeList
            workerToBikeList.push_back(currWorkerPairs);
        }
        
        // initialize all value to false, to signify no bikes have been taken
        vector<bool> bikeStatus(bikes.size());
        // initialize all values to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        
        while (!pq.empty()){
            // pop the worker-bike pair with smallest distance
            auto [distance, worker, bike] = pq.top();
            pq.pop();
            
            if (!bikeStatus[bike]){
                // If the bike is free, assign the bike to the worker
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
            }
            else{
                // otherwise, add the next closest bike for the current worker to the priority queue
                tuple<int, int, int> nextClosestBike = workerToBikeList[worker].back();
                workerToBikeList[worker].pop_back();
                pq.push(nextClosestBike);
            }
        }
        
        return workerStatus;
    }
};
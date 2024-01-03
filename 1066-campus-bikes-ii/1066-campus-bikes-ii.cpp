class Solution {
private:
    // Manhattan Distance
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    // Count the number of ones using Brian Kernighan's algorithm
    int countNumOfOnes(int mask){
        int count = 0;
        while(mask != 0){
            mask &= (mask - 1);
            ++count;
        }
        return count;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = bikes.size(), n = workers.size();
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Initially both distance sum and mask is 0
        minHeap.push({0, 0});
        
        while (!minHeap.empty()){
            auto [currentDistSum, currentMask] = minHeap.top();
            minHeap.pop();
            
            // Continue if the mask is already traversed
            if (visited.find(currentMask) != visited.end())
                continue;
            
            // Marking the mask as visited
            visited.insert(currentMask);
            
            // Next worker index would be equal to the number of 1's in currentMask
            int workerIndex = countNumOfOnes(currentMask);
            
            // Return the current distance sum if all workers are covered
            if (workerIndex == n)
                return currentDistSum;
           
            
            for (int bikeIndex = 0; bikeIndex < m; ++bikeIndex){
                // Checking if the bike at bikeIndex has been assigned or not
                if ((currentMask & (1 << bikeIndex)) == 0){
                    int nextStateDistSum = currentDistSum + findDistance(workers[workerIndex], bikes[bikeIndex]);
                    
                    // Put the next state pair into the priority queue
                    int newStateMask = currentMask | (1 << bikeIndex);
                    minHeap.push({nextStateDistSum, newStateMask});
                }
            }
        }
        
        // This statement will never be executed provided that there is at least one bike per a worker
        return -1;
    }
    
};
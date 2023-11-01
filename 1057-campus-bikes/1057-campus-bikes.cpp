class Solution {
private:
    int findDistance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        // calculate the distance between each worker and bike
        vector<vector<int>> allTriplets;
        for (int i = 0; i < workers.size(); ++i){
            for (int j = 0; j < bikes.size(); ++j){
                allTriplets.push_back({findDistance(workers[i], bikes[j]), i, j});
            }
        }
        
        // sort the triplets. By default, sorting will prioritize the tuple's first value,
        // then second value, and finally the third value
        sort(allTriplets.begin(), allTriplets.end());
        
        // initialize all values to False, to signify no bikes have been taken
        vector<bool> usedBikes(bikes.size());
        // initialize all values to -1, to signify no worker has a bike
        vector<int> ans(workers.size(), -1);
        // keep track of how many worker-bike pairs have been made
        int pairCount = 0;
        
        for (int i = 0; i < allTriplets.size(); ++i){
            // If both worker and bike are free, assign the bike to the worker
            // and mark the bike as taken
            int dist = allTriplets[i][0], worker = allTriplets[i][1], bike = allTriplets[i][2];
            if (!usedBikes[bike] && ans[worker] == -1){
                usedBikes[bike] = true;
                ans[worker] = bike;
                ++pairCount;
                
                // If all the workers have the bike assigned, we can stop
                if (pairCount == workers.size())
                    return ans;
            }
            
            
        }
            
        return ans;
    }
};
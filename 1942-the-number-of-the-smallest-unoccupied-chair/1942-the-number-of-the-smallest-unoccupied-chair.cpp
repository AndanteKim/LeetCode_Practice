class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Min-heap for available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        // Initially all chairs are free.
        for (int i = 0; i < n; ++i) availableChairs.push(i);
        // Min-heap to track when chairs will vacated
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;
        
        // To store both arrival and leave events
        vector<pair<int, int>> events;
        // Populate events with {arrival, friendIndex}, {leave, ~friendIndex};
        for (int i = 0; i < n; ++i){
            // Arrival
            events.push_back({times[i][0], i});
            // Leave
            events.push_back({times[i][1], ~i});
        }
        
        // Sort ascending order by event
        sort(events.begin(), events.end());
        
        for (const auto& event : events){
            auto [arrive, friendIndex] = event;
            
            //Free up chairs when friends leave
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrive){
                auto [_, chairIndex] = occupiedChairs.top();
                occupiedChairs.pop();
                availableChairs.push(chairIndex);
            }
            
            if (friendIndex >= 0){  // Friend arrives
                int chairIndex = availableChairs.top();
                availableChairs.pop();
                if (friendIndex == targetFriend)
                    return chairIndex;
                // Mark when the chair will be vacated.
                occupiedChairs.push({times[friendIndex][1], chairIndex});
            }
        }
        
        // Should not come to this point
        return -1;
    }
};
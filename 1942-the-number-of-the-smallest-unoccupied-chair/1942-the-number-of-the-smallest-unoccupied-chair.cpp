class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0], n = times.size();
        set<int> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        // Track next available chair number
        int nextChair = 0;
        sort(times.begin(), times.end());
        
        for (const auto& time : times){
            int arrival = time[0], leave = time[1];
            
            // Free up chairs based on current time
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrival){
                availableChairs.insert(leavingQueue.top().second);
                leavingQueue.pop();
            }
            
            int currentChair;
            // Assign chair from available set or increment new chair
            if (!availableChairs.empty()){
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            }
            else{
                currentChair = nextChair++;
            }
            
            // Check if it's the target friend
            if (targetArrival == arrival)
                return currentChair;
            
            // Push current leave time and chair
            leavingQueue.push({leave, currentChair});
        }
        
        
        return -1;
    }
};
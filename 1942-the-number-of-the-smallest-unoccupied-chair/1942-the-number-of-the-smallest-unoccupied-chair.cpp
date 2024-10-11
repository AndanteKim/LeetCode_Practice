class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        int n = times.size();
        
        vector<tuple<int, int, int>> chronicle;
        for (int i = 0; i < n; ++i)
            chronicle.push_back({times[i][0], times[i][1], i});
        sort(chronicle.begin(), chronicle.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        int nextChair = 0;
        for (const auto& time : chronicle){
            auto [arrival, leave, index] = time;
            
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrival){
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }
            
            int currentChair;
            if (availableChairs.empty())
                currentChair = nextChair++;
            else{
                currentChair = availableChairs.top();
                availableChairs.pop();
            }
            if (targetArrival == arrival)
                return currentChair;
            
            leavingQueue.push({leave, currentChair});
        }
        
        
        return -1;
    }
};
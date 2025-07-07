class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(), maxDay = 0;

        for (vector<int>& event : events)
            maxDay = max(maxDay, event[1]);
        
        sort(events.begin(), events.end());
        int ans = 0, j = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 1; i <= maxDay; ++i){
            while (j < n && events[j][0] <= i)
                minHeap.push(events[j++][1]);
            
            while(!minHeap.empty() && minHeap.top() < i) minHeap.pop();

            if (!minHeap.empty()){
                ++ans;
                minHeap.pop();
            }
        }

        return ans;
    }
};
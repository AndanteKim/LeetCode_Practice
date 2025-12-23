class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Create a list to store the pair (end time, value) for events
        int n = events.size();

        // Sort the events by their start time
        sort(events.begin(), events.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int maxVal = 0, maxSum = 0;
        for (const auto& e : events) {
            // Pop all valid events from the priority queue and take their maximum
            int start = e[0], end = e[1], val = e[2];

            while (!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // Calculate the maximum sum by adding the current event's value and the best previous event's value
            maxSum = max(maxSum, maxVal + val);

            // Push the current event's end time and value into the heap
            pq.push({end, val});
        }

        return maxSum;
    }
};
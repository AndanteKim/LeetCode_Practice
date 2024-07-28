class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        
        for (vector<int>& edge : edges){
            int start = edge[0], end = edge[1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        
        // Dist1[i] stores the minimum time taken to reach node i from node1. dist2[i] stores the
        // second minimum time taken to reach node from node1. Freq[i] stores the number of times
        // node is popped out of the heap.
        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX), freq(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 1});
        dist1[1] = 0;
        
        while (!minHeap.empty()){
            auto [timeTaken, node] = minHeap.top(); minHeap.pop();
            ++freq[node];
            
            // If the node is being visited for the second time and is 'n', return the answer.
            if (node == n && freq[node] == 2)
                return timeTaken;
            
            // If the current light is read, wait till the path turns green.
            if ((timeTaken / change) % 2)
                timeTaken = change * (timeTaken / change + 1) + time;
            else
                timeTaken += time;
            
            for (int neighbor : adj[node]){
                // Ignore nodes that have already popped out twice.
                if (freq[neighbor] == 2) continue;
                
                // Update dist1 if it's more than the current timeTaken and store its value in
                // dist2 since that becomes the second minimum value now.
                if (dist1[neighbor] > timeTaken){
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = timeTaken;
                    minHeap.push({timeTaken, neighbor});
                }
                else if (dist2[neighbor] > timeTaken && timeTaken != dist1[neighbor]){
                    dist2[neighbor] = timeTaken;
                    minHeap.push({timeTaken, neighbor});
                }
            }
        }
        
        return 0;
    }
};
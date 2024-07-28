class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        
        // Build the adjacency list.
        for (vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        queue<pair<int, int>> queue;
        // Start with node 1, with its minimum distance.
        queue.push({1, 1});
        dist1[1] = 0;
        
        while (!queue.empty()){
            auto [node, freq] = queue.front(); queue.pop();
            
            int timeTaken = (freq == 1)? dist1[node] : dist2[node];
            
            // If timeTaken falls under the red bracket, wait until the path turns green.
            if ((timeTaken / change) % 2)
                timeTaken = change * (timeTaken / change + 1) + time;
            else
                timeTaken += time;
            
            for (int neighbor : adj[node]){
                if (dist1[neighbor] == -1){
                    dist1[neighbor] = timeTaken;
                    queue.push({neighbor, 1});
                }
                else if (dist2[neighbor] == -1 && timeTaken != dist1[neighbor]){
                    if (neighbor == n) return timeTaken;
                    dist2[neighbor] = timeTaken;
                    queue.push({neighbor, 2});
                }
            }
        }
        
        return 0;
    }
};
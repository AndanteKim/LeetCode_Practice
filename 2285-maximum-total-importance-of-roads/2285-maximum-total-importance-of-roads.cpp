class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;
        
        for (auto& road:roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (auto& [node, network] : adj)
            pq.push({network.size(), node});
        
        int val = n;
        vector<int> importance(n);
        while (!pq.empty() && val >= 1){
            importance[pq.top().second] = val;
            pq.pop();
            --val;
        }
        
        long long ans = 0;
        vector<bool> visited(n);
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                visited[node] = true;
                
                for (int neighbor : adj[node])
                    ans += importance[node] + importance[neighbor];
            }
        }
        
        return ans >> 1;
    }
};
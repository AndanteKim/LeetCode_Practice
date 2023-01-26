class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto &edge : flights){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        
        while (stops <= k && !q.empty()){
            int sz = q.size();
            while (sz--){
                auto [node, distance] = q.front();
                q.pop();
                for (auto &[neighbour, price] : adj[node]){
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            ++stops;
        }
        
        return dist[dst] == numeric_limits<int>::max()? -1: dist[dst];
    }
};
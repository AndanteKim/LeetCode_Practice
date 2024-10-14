class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (const auto& e : flights){
            int start = e[0], end = e[1], cost = e[2];
            adj[start].push_back({end, cost});
        }
        
        vector<int> stops(n, std::numeric_limits<int>::max());
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push({0, src, 0});
        
        while (!minHeap.empty()){
            auto [dist, node, steps] = minHeap.top(); minHeap.pop();
            
            // If we've already encountered a path with a lower cost and fewer stops
            // or the number of stops exceeds the limit.
            if (steps > stops[node] || steps > k + 1) continue;
            
            // If we've reached the destination with the fewest steps, return the current lowest cost
            if (node == dst) return dist;
            
            stops[node] = steps;
            for (const auto& [neighbor, cost] : adj[node])
                minHeap.push({dist + cost, neighbor, steps + 1});
        }
        
        return -1;
    }
};
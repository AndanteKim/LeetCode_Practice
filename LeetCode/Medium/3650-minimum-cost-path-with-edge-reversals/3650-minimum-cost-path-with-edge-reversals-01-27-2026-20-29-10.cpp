class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector graph(n, vector<pair<int, int>>{});
        
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        vector<int> dist(n, std::numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        dist[0] = 0;
        minHeap.push({0, 0});

        while (!minHeap.empty()) {
            const auto [cost, u] = minHeap.top(); minHeap.pop();

            if (u == n - 1) return cost;

            for (const auto [v, w] : graph[u]) {
                int newCost = cost + w;

                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    minHeap.push({newCost, v});
                }
            }
        }

        return -1;
    }
};
class Solution {
private:
    int n;
    long long k;
    bool check(int mid, vector<vector<pair<int, int>>>& graph) {
        vector<long long> dist(n, std::numeric_limits<long long>::max());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > k) return false;

            if (u == n - 1) return true;

            if (d > dist[u]) continue;

            for (const auto& [v, w] : graph[u]){
                if (w < mid) continue;

                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        this -> n = online.size();
        this -> k = k;
        vector<vector<pair<int, int>>> graph(n);
        int left = std::numeric_limits<int>::max(), right = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!(online[u] && online[v])) continue;
            graph[u].push_back({v, w});
            left = min(left, w);
            right = max(right, w);
        }

        if (!check(left, graph)) return -1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid, graph)) left = mid + 1;
            else right = mid - 1;
        }

        return right;
    }
};
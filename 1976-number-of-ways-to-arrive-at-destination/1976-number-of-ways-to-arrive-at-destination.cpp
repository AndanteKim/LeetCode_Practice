class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        const int MOD = 1'000'000'007;

        // Build adjacency list
        for (const auto& road : roads){
            int u = road[0], v = road[1], time = road[2];

            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        // Store the shortest time to each node
        vector<long long> shortestTime(n, std::numeric_limits<long long>::max());
        // Number of ways to reach each node in the shortest time
        vector<int> pathCount(n, 0);

        shortestTime[0] = 0;    // Distance to source is 0
        pathCount[0] = 1;       // 1 way to reach node 0


        // Min-heap (priority queue) for Dijkstra
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        minHeap.push({0, 0});   // {time, node}
        
        while (!minHeap.empty()){
            auto [currTime, currNode] = minHeap.top(); minHeap.pop();   // Current the shortest time

            // Skip outdated distances
            if (currTime > shortestTime[currNode])
                continue;
            
            for (const auto& [neighbor, runTime] : graph[currNode]){
                // Found a new shortest path → Update the shortest time and reset path count
                if (currTime + runTime < shortestTime[neighbor]){
                    shortestTime[neighbor] = currTime + runTime;
                    pathCount[neighbor] = pathCount[currNode];
                    minHeap.push({shortestTime[neighbor], neighbor});
                }

                // Found another way with the same shortest time → Add to path count
                else if (currTime + runTime == shortestTime[neighbor]){
                    pathCount[neighbor] = (pathCount[neighbor] + pathCount[currNode]) % MOD;
                }
            }
        }

        return pathCount[n - 1] % MOD;
    }
};
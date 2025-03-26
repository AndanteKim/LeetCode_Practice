class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<vector<pair<int, int>>> graph(n);
        
        // Build adjacent graph
        for (const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, s});
        vector<int> minDistances(n, std::numeric_limits<int>::max());

        while (!minHeap.empty()){
            auto [currDist, currNode] = minHeap.top(); minHeap.pop();
            
            // If we found infinite loop, then skip this
            if (currDist > minDistances[currNode]) continue;

            // Update the minimum distance
            minDistances[currNode] = currDist;

            for (const auto& [neighbor, weight] : graph[currNode]){
                minHeap.push({currDist + weight, neighbor});
            }
        }

        int unknownCount = 0, minDistance = std::numeric_limits<int>::max();
        // Count the unknown distance for each node
        for (int node : marked){
            if (minDistances[node] == std::numeric_limits<int>::max())
                ++unknownCount;

            minDistance = min(minDistance, minDistances[node]);
        }

        // If all the minimum distances of marked nodes are unknown, then there's no path.
        return (unknownCount == marked.size())? -1 : minDistance;
    }
};
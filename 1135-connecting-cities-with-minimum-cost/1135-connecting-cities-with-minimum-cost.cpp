class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Prim algorithm
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (const auto& connection : connections){
            graph[connection[0]].push_back({connection[1], connection[2]});
            graph[connection[1]].push_back({connection[0], connection[2]});
        }

        unordered_set<int> mst;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nextNodes;
        nextNodes.push({0, 1});
        int minCost = 0;

        while (mst.size() != n){
            if (nextNodes.empty()) return -1;

            auto [cost, node] = nextNodes.top(); nextNodes.pop();

            if (mst.find(node) != mst.end())
                continue;
            
            mst.insert(node);
            minCost += cost;

            for (const auto& [nextNode, nextCost] : graph[node]){
                if (mst.find(nextNode) != mst.end()) continue;
                nextNodes.push({nextCost, nextNode});
            }
        }

        return minCost;
    }
};
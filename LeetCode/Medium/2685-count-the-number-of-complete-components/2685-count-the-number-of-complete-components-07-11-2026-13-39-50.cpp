class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_map<string, int> componentFreq;

        for (int v = 0; v < n; ++v) graph[v].push_back(v);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int v = 0; v < n; ++v) {
            vector<int> neighbors = graph[v];
            sort(neighbors.begin(), neighbors.end());

            string key = "";
            for (int num : neighbors) key += to_string(num) + ",";
            ++componentFreq[key];
        }

        int completeCount = 0;
        for (const auto& [comps, freq] : componentFreq) {
            int size = count(comps.begin(), comps.end(), ',');
            if (size == freq) ++completeCount;
        }

        return completeCount;
    }
};
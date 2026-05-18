class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Base case
        if (arr.size() <= 1) return 0;

        int n = arr.size();
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; ++i) graph[arr[i]].push_back(i);

        unordered_set<int> visited;
        visited.insert(0);
        int ans = 0;
        vector<int> currs{0};

        while (!currs.empty()) {
            vector<int> next;
            for (int node : currs) {
                if (node == n - 1) return ans;

                for (int child : graph[arr[node]]) {
                    if (visited.contains(child)) continue;
                    visited.insert(child);
                    next.push_back(child);
                }

                graph[arr[node]].clear();

                for (int child : vector<int>{node - 1, node + 1}) {
                    if (0 <= child && child < n && !visited.contains(child)) {
                        visited.insert(child);
                        next.push_back(child);
                    }
                }
            }

            currs = next;
            ++ans;
        }




        return -1;
    }
};
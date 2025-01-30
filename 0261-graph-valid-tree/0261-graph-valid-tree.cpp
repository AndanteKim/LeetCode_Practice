class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>& graph, unordered_set<int>& seen){
        if (seen.count(node))
            return false;

        seen.insert(node);
        for (int neighbor : graph[node]){
            if (neighbor == parent)
                continue;
            
            if (seen.count(neighbor) || !dfs(neighbor, node, graph, seen))
                return false;
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Base case
        if (edges.size() != n - 1)
            return false;

        vector graph(n, vector<int>());

        for (const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // We return True if and only if no cycles were detected,
        // and the entire graph has been reached.
        unordered_set<int> seen;
        return dfs(0, -1, graph, seen) && seen.size() == n;
    }
};
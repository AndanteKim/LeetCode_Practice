class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size()) return false;

        vector graph(n, vector<int>());

        for (const vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> parent{{0, -1}};
        queue<int> q;
        q.push(0);

        while (!q.empty()){
            int node = q.front(); q.pop();

            for (int neighbor : graph[node]){
                if (neighbor == parent[node]) continue;

                if (parent.count(neighbor)) return false;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
        
        return parent.size() == n;
    }
};
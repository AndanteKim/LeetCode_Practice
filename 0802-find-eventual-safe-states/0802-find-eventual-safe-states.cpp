class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector adj(n, vector<int>());

        for (int start = 0; start < n; ++start){
            for (int end : graph[start]){
                adj[end].push_back(start);
                ++indegree[start];
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int node = 0; node < n; ++node)
            if (indegree[node] == 0)
                q.push(node);

        vector<bool> safe(n);
        while (!q.empty()){
            int node = q.front(); q.pop();
            safe[node] = true;

            // Delete the edge "node -> neighbor".
            for (int neighbor : adj[node]){
                --indegree[neighbor];
                if (indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        vector<int> ans;
        for (int node = 0; node < n; ++node)
            if (safe[node])
                ans.push_back(node);

        return ans;
    }
};
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector count(n, vector<int>(26, 0));
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            ++indegree[edge[1]];
        }
        
        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; ++i){
            if (indegree[i] == 0) q.push(i);
        }

        int ans = 0, nodesSeen = 0;
        while (!q.empty()){
            int node = q.front(); q.pop();
            ++nodesSeen;
            ans = max(ans, ++count[node][colors[node] - 97]);

            for (int neighbor : adj[node]){
                // Try to update the frequency of colors for neighbor to include paths
                // that use node -> neighbor edge
                for (int i = 0; i < 26; ++i){
                    count[neighbor][i] = max(count[neighbor][i], count[node][i]);
                }
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return (nodesSeen < n)? -1 : ans;
    }
};
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<vector<int>> graph(n);
        vector<int> ans(m);
        
        for (int i = 0; i < n; ++i)
            graph[i].push_back(i + 1);
        
        for (int i = 0; i < m; ++i){
            int start = queries[i][0], end = queries[i][1];
            graph[start].push_back(end);
            
            vector<int> visited(n, std::numeric_limits<int>::max());
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;
            dijkstra.push({0, 0});
            
            while (!dijkstra.empty()){
                auto [steps, node] = dijkstra.top(); dijkstra.pop();
                
                if (steps >= visited[node]) continue;
                
                if (node == n - 1){
                    ans[i] = steps;
                    break;
                }
                
                visited[node] = steps;
                for (int neighbor : graph[node])
                    dijkstra.push({steps + 1, neighbor});
            }
        }
        
        return ans;
    }
};
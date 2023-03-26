class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n);
        vector<int> indegree(n);
        
        for (int edge : edges) if (edge != -1) ++indegree[edge];
        
        queue<int> *q = new queue<int>;
        for(int node = 0; node < n; ++node){
            if (indegree[node] == 0) q -> push(node);
        }
        
        while(!q -> empty()){
            int node = q -> front();
            q -> pop();
            visited[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1){
                --indegree[neighbor];
                if (indegree[neighbor] == 0) q -> push(neighbor);
            }
        }
        
        int ans = -1;
        for (int node = 0; node < n; ++node){
            if (!visited[node]){
                int neighbor = edges[node];
                int count = 1;
                visited[node] = true;
                while (neighbor != node){
                    visited[neighbor] = true;
                    ++count;
                    neighbor = edges[neighbor];
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
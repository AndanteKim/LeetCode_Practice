class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indegrees(n, 0);
        for (auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            ++indegrees[edge[1]];
        }
        
        queue<int> queue;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) queue.push(i);
        }
        
        vector<set<int>> res(n);
        while (!queue.empty()){
            int sz = queue.size();
            while(sz--){
                int curr = queue.front();
                for (int i : adj[curr]){
                    --indegrees[i];
                    res[i].insert(curr);
                    if (indegrees[i] == 0) queue.push(i);
                    for (int node : res[curr]) res[i].insert(node);
                }
                queue.pop();
            }
        }
        
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i){
            for (int node : res[i])
                ans[i].push_back(node);
        }
        return ans;
    }
};
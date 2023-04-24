class Solution {
    int bfs(int bossID, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& informTime){
        int totalTime = 0;
        queue<pair<int, int>> queue;
        queue.push({bossID, 0});
        
        while (!queue.empty()){
            auto [current, time] = queue.front();
            queue.pop();
            if (!visited[current]){
                visited[current] = true;
                for (int neighbor : adj[current]){
                    queue.push({neighbor, time + informTime[current]});
                }
                totalTime = max(totalTime, time + informTime[current]);
            }
        }
        return totalTime;
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < manager.size(); ++i){
            if (manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }
        
        int ans = bfs(headID, visited, adj, informTime);
        return ans;
    }
};
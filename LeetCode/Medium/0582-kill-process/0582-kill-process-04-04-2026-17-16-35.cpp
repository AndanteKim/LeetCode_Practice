class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        int n = pid.size();

        for (int i = 0; i < n; ++i){ 
            graph[ppid[i]].push_back(pid[i]);
        }

        vector<int> ans;
        queue<int> q; q.push(kill);

        while (!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            
            for (int neighbor : graph[node])
                q.push(neighbor);
            
        }

        return ans;
    }
};
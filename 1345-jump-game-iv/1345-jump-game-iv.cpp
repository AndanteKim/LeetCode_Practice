class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        unordered_map<int, vector<int>> graph;
        
        for (int i = 0; i < n; ++i) graph[arr[i]].push_back(i);
    
        queue<int> q({0});
        vector<bool> visited(n, false);
        int step = 0;
        visited[0] = true;
        
        while (!q.empty()){
            int len = q.size();
            while (--len >= 0){
                int curr = q.front();
                q.pop();
                
                if (curr == n - 1) return step;
                
                if (curr + 1 < n && !visited[curr + 1]){
                    q.push(curr + 1);
                    visited[curr + 1] = true;
                }
                
                if (curr - 1 >= 0 && !visited[curr - 1]){
                    q.push(curr - 1);
                    visited[curr - 1] = true;
                }
                
                if (graph.find(arr[curr]) != graph.end()){
                    for (int next : graph[arr[curr]]){
                        if (!visited[next]){
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                    
                    graph.erase(arr[curr]);
                }
            }
            ++step;
        }
        
        return -1;
    }
};
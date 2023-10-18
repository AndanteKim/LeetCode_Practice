class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        // topological sort + kahn algorithm
        unordered_map<int, vector<int>> graph;
        vector<int> maxTime(n), indegree(n);
        for (vector<int>& relation : relations){
            graph[relation[0] - 1].push_back(relation[1] - 1);
            ++indegree[relation[1] - 1];
        }
        
        queue<int> queue;
        for (int i = 0; i < n; ++i){
            if (indegree[i] == 0)
                queue.push(i);
            maxTime[i] = time[i];
        }
        
        while(!queue.empty()){
            int node = queue.front();
            queue.pop();
            
            for (int neighbor : graph[node]){
                --indegree[neighbor];
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                if (indegree[neighbor] == 0)
                    queue.push(neighbor);
            }
        }
        
        return *max_element(maxTime.begin(), maxTime.end());
    }
};
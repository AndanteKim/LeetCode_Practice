class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n + 1); // or indegree
        vector<int> indegree(n + 1);
        
        for (vector<int>& relation : relations){
            graph[relation[0]].push_back(relation[1]);
            ++indegree[relation[1]];
        }
        
        vector<int> queue;
        // We use list here since we're not popping from front this code
        for (int node = 1; node <= n; ++node) if (!indegree[node]) queue.push_back(node);
        int semesters = 0, steps = 0;
        
        // start learning with BFS
        while (!queue.empty()){
            vector<int> nextQueue;
            ++steps;
            for (int node : queue){
                ++semesters;
                for (int endNode : graph[node]){
                    --indegree[endNode];
                    // If all preprequisite courses learned
                    if (!indegree[endNode])
                        nextQueue.push_back(endNode);
                }
            }
            queue = nextQueue;
        }
        
        return semesters == n? steps : -1;
    }
};
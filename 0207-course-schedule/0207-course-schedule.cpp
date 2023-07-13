class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        
        for (vector<int>& prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        
        queue<int> queue;
        for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) queue.push(i);
        
        int nodesVisited = 0;
        while (!queue.empty()){
            int curr = queue.front();
            queue.pop();
            ++nodesVisited;
            for (int neighbor : adj[curr]){
                --indegree[neighbor];
                if (!indegree[neighbor]) queue.push(neighbor);
            }
        }
        
        return nodesVisited == numCourses;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        
        for (auto& prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        
        queue<int> queue;
        
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                queue.push(i);
        
        vector<int> ans;
        while (!queue.empty()){
            int curr = queue.front(); queue.pop();
            ans.push_back(curr);
            
            for (int neighbor : adj[curr]){
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    queue.push(neighbor);
            }
        }
        
        return ans.size() == numCourses? ans : vector<int>{};
    }
};
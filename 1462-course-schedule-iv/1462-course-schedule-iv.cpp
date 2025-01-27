class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<bool> ans(queries.size(), false);

        for (int i = 0; i < prerequisites.size(); ++i){
            int start = prerequisites[i][0], end = prerequisites[i][1];
            graph[start].push_back(end);
        }

        for (int i = 0; i < queries.size(); ++i){
            int start = queries[i][0], end = queries[i][1];
            queue<int> q;
            q.push(start);
            vector<bool> visited(numCourses);

            while (!q.empty()){
                int curr = q.front(); q.pop();
        
                visited[curr] = true;
                if (curr == end){
                    ans[i] = true;
                    break;
                }

                for (int neighbor : graph[curr]){
                    if (!visited[neighbor]){
                        q.push(neighbor);
                    }
                }
            }
        }

        return ans;
    }
};
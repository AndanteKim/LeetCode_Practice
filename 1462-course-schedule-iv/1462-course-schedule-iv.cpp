class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector adj(numCourses, vector<int>());
        vector<int> indegree(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i){
            int start = prerequisites[i][0], end = prerequisites[i][1];
            adj[start].push_back(end);
            ++indegree[end];
        }

        queue<int> q;
        for (int node = 0; node < numCourses; ++node){
            if (indegree[node] == 0)
                q.push(node);
        }

        // Map from the node as key to the set of prerequisite nodes.
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty()){
            int node = q.front(); q.pop();

            for (int neighbor : adj[node]){
                // Add node and prerequisite of node to the prerequisites of adj
                nodePrerequisites[neighbor].insert(node);
                for (int prerequisite : nodePrerequisites[node])
                    nodePrerequisites[neighbor].insert(prerequisite);
            
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); ++i){
            int start = queries[i][0], end = queries[i][1];
            ans.push_back(nodePrerequisites[end].count(start)? true : false);
        }

        return ans;
    }
};
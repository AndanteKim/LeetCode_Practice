class Solution {
private:
    enum status {WHITE, GRAY, BLACK};
    bool isPossible = true;
    
    void dfs(int node, vector<vector<int>>& adj, unordered_map<int, status>& color, vector<int>& ans){
        // Don't recurse further if we found a cycle already.
        if (!isPossible)
            return;
        
        // Start the recursion
        color[node] = status::GRAY;
        
        // Traverse on neighboring vertices.
        for (int neighbor : adj[node]){
            if (color[neighbor] == status::WHITE)
                dfs(neighbor, adj, color, ans);
            else if (color[neighbor] == status::GRAY){
                // An edge to a GRAY vertex represents a cycle.
                isPossible = false;
            }
        }
        
        // Recursion ends. We mark it as black.
        color[node] = status::BLACK;
        ans.push_back(node);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // Create the adjacency list representation of the graph.
        for (auto& prerequisite : prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        // By default, all vertices are WHITE.
        unordered_map<int, status> color;
        for (int k = 0; k < numCourses; ++k)
            color[k] = status::WHITE;
        
        vector<int> ans;
        
        // If the node is unprocessed, then call dfs on it.
        for (int i = 0; i < numCourses && isPossible; ++i){
            if (color[i] == status::WHITE)
                dfs(i, adj, color, ans);
        }
        
        
        if (isPossible){
            reverse(ans.begin(), ans.end());
            return ans;
        }
        
        return vector<int>{};
    }
};
class Solution {
private:
    int n;

    // Checks if the graph is bipartite starting from the given node
    bool isBipartite(int node, vector<vector<int>>& graph, vector<int>& colors){

        for (int neighbor : graph[node]){
            // If a neighbor has the same color as the current node, the graph is not bipartite
            if (colors[node] == colors[neighbor])
                return false;

            // If the neighbor is already colored, skip it
            if (colors[neighbor] != -1)
                continue;
            
            // Assign the opposite color to the neighbor
            colors[neighbor] = (colors[node] + 1) % 2;

            // Recursively check bipartiteness for the neighbor; return false if it fails
            if (!isBipartite(neighbor, graph, colors))
                return false;
        }

        // If all neighbors are properly colored, return true
        return true;
    }

    // Compute the longest shortest path (height) in the graph starting from the source node
    int getLongestShortestPath(int sourceNode, vector<vector<int>>& graph){
        // Initialize a queue for BFS and a visited array
        queue<int> q;
        q.push(sourceNode);
        vector<bool> visited(n, false);
        visited[sourceNode] = true;
        int dist = 0;

        // Perform BFS layer by layer
        while (!q.empty()){
            // Process all nodes in the current layer
            int sz = q.size();
            for (int i = 0; i < sz; ++i){
                int currNode = q.front(); q.pop();

                // Visit all unvisited neighbors of the current node
                for (int neighbor : graph[currNode]){
                    if (visited[neighbor])
                        continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                    
                }
            }

            // Increment the distance for each layer
            ++dist;
        }

        // Return the total distance (longest shortest path)
        return dist;
    }

    // Calculates the maximum number of groups for a connected component
    int getNumberOfGroupsForComponent(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& distances){
        // Start with the distance of the current node as the maximum
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        // Recursively calculate the maximum for all unvisited neighbors
        for (int neighbor : graph[node]){
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups, getNumberOfGroupsForComponent(neighbor, graph, visited, distances));
        }

        return maxNumberOfGroups;
    }

public:
    // Main function to calculate the maximum number of magnificent sets
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this -> n = n;

        // Create adjacency list for the graph
        vector graph(n, vector<int>());
        for (const vector<int>& edge : edges){
            // Transition to 0-index
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        // Initialize color array to -1
        vector<int> colors(n, -1);

        // Check if the graph is bipartite
        for (int node = 0; node < n; ++node){
            if (colors[node] != -1)
                continue;

            // Start coloring from uncolored nodes
            colors[node] = 0;

            // If the graph isn't bipartite, return -1
            if (!isBipartite(node, graph, colors))
                return -1;
        }
        
        // Calculate the longest shortest path for each node
        vector<int> distances(n);
        for (int node = 0; node < n; ++node){
            distances[node] = getLongestShortestPath(node, graph);
        }
        
        // Calculate the total maximum number of groups across all components
        int maxNumberOfGroups = 0;
        vector<bool> visited(n);
        for (int node = 0; node < n; ++node){
            if (visited[node])
                continue;

            // Add the number of groups for this component to the total
            maxNumberOfGroups += getNumberOfGroupsForComponent(node, graph, visited, distances);
        }

        return maxNumberOfGroups;
    }
};
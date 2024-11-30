class Solution {
private:
    bool detectedCycleNodes(int currNode, vector<vector<int>>& adjacencyMatrix, vector<bool>& visited, vector<bool>& isInCycle, vector<int>& parent){
        visited[currNode] = true;   // Mark current node as visited
        for (int neighbor : adjacencyMatrix[currNode]){
            if (!visited[neighbor]){
                parent[neighbor] = currNode;    // Set parent for backtracking
                if (detectedCycleNodes(neighbor, adjacencyMatrix, visited, isInCycle, parent))
                    return true;    // Return true if cycle detected
            }
            else if (parent[currNode] != neighbor){     // Cycle detected
                isInCycle[neighbor] = true;     // Mark the start of the cycle
                int tempNode = currNode;
                // Backtrack to mark all nodes in the cycle
                while (tempNode != neighbor){
                    isInCycle[tempNode] = true;
                    tempNode = parent[tempNode];
                }
                return true;
            }
        }
        
        return false;   // No cycle found in the cycle
    }
    
    // DFS to calculate distances from the cycle nodes
    void calculateDistances(int currNode, int currDistance, vector<vector<int>>& adjacencyMatrix, vector<bool>& visited, vector<bool>& isInCycle, vector<int>& distances){
        visited[currNode] = true;   // Mark node as visited
        distances[currNode] = currDistance;     // Set distance for current node
        
        for (int neighbor : adjacencyMatrix[currNode]){
            if (!visited[neighbor]){
                int newDistance = isInCycle[neighbor]? 0 : currDistance + 1;    // Reset if on cycle
                calculateDistances(neighbor, newDistance, adjacencyMatrix, visited, isInCycle, distances);
            }
        }
    }
    
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyMatrix(n);
        vector<bool> visited(n, false), isInCycle(n, false);
        vector<int> parent(n), distances(n);
        
        // Build adjacency list for the graph
        for (const auto& e : edges){
            adjacencyMatrix[e[0]].push_back(e[1]);
            adjacencyMatrix[e[1]].push_back(e[0]);
        }
        
        // Detect and mark cycle nodes
        detectedCycleNodes(0, adjacencyMatrix, visited, isInCycle, parent);
        
        // Reset visited array before distance calculation
        fill(visited.begin(), visited.end(), false);
        
        // Calculate distances starting from any cycle node
        for (int node = 0; node < n; ++node){
            if (isInCycle[node]){
                calculateDistances(node, 0, adjacencyMatrix, visited, isInCycle, distances);
                break;      // Only need to start from one cycle node
            }
        }
        
        return distances;
    }
};
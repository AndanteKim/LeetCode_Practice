class Solution {
private:
    int k;
    int dfs(int parentNode, int currNode,
            vector<int> adjList[], vector<int>& values,
            int& componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (int neighborNode : adjList[currNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(currNode, neighborNode, adjList, values,
                           componentCount);

                // Ensure the sum stays within bounds
                sum %= k;
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += values[currNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0)
            ++componentCount;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        this -> k = k;

        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(-1, 0, adjList, values, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }
};
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize a 2D vector to store the minimum transformation cost
        // between any two characters
        vector<vector<long long>> minCost(26, vector<long long>(26, INT_MAX));
        
        // Fill the initial transformation costs from the given original,
        // changed, and cost arrays
        for (int i = 0; i < original.size(); ++i){
            int startC = original[i] - 97, endC = changed[i] - 97, cst = cost[i];
            minCost[startC][endC] = min(minCost[startC][endC], (long long)cst);
        }
        
        // Use Floyd-Warshall algorithm to find the shortest path between any
        // two characters
        for (int k = 0; k < 26; ++k){
            for (int i = 0; i < 26; ++i){
                for (int j = 0; j < 26; ++j){
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
        
        // Calculate the total minimum cost to transform the source string to
        // the target string
        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i){
            if (source[i] == target[i])
                continue;
            
            int src = source[i] - 97, dst = target[i] - 97;
            
            // If the transformation is not possible, return -1
            if (minCost[src][dst] >= INT_MAX)
                return -1;
            
            totalCost += minCost[src][dst];
        }
        
        return totalCost;
    }
};
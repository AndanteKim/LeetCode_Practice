class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Create a graph representation of character conversions
        vector<vector<pair<int, int>>> adj(26);
        
        // Populate the adjacency list with character conversions
        int conversionCount = original.size();
        
        for (int i = 0; i < conversionCount; ++i){
            adj[original[i] - 97].push_back({changed[i] - 97, cost[i]});
        }
        
        // Calculate shortest paths for all possible character conversions
        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
        
        for (int i = 0; i < 26; ++i)
            minConversionCosts[i] = dijkstra(i, adj);
        
        // Calculate the total cost of converting source to target
        long long totalCost = 0;
        int stringLength = source.length();
        
        for (int i = 0; i < stringLength; ++i){
            if (source[i] != target[i]){
                long long charConversionCost = minConversionCosts[source[i] - 'a'][target[i] - 'a'];
                if (charConversionCost == -1)
                    return -1;  // Conversion not possible
                
                totalCost += charConversionCost;
            }
        }
        
        return totalCost;
    }
    
private:
    // Find minimum conversion costs from a starting character to all other
    // characters
    vector<long long> dijkstra(int startChar, const vector<vector<pair<int, int>>>& adj){
        // Priority queue to store character with their conversion cost, sorted by cost
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        // Initialize the starting character with cost 0
        pq.push({0, startChar});
        
        // Array to store the minimum conversion cost to each character
        vector<long long> minCosts(26, -1);
        
        while (!pq.empty()){
            auto [currCost, currChar] = pq.top(); pq.pop();
            
            if (minCosts[currChar] != -1 && minCosts[currChar] < currCost)
                continue;
            
            // Explore all possible conversions from the current character
            for (auto& [targetChar, conversionCost] : adj[currChar]){
                long long newCost = currCost + conversionCost;
                
                // If we found a cheaper conversion, update its cost
                if (minCosts[targetChar] == -1 || newCost < minCosts[targetChar]){
                    minCosts[targetChar] = newCost;
                    // Add the updated conversion to the queue for further
                    // exploration
                    pq.push({newCost, targetChar});
                }
            }
        }
        
        // Return the array of minimum conversion costs from the starting
        // character to all others
        return minCosts;
    }
};
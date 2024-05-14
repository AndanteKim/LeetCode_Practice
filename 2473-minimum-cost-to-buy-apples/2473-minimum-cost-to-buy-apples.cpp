class Solution {
private:
    int k, n;
    // Find the minimum cost to buy an apple from the start city
    long long shortestPath(vector<vector<pair<int, int>>>& graph, vector<int>& appleCost, int startCity){
        
        // Initialize the heap with the starting city
        // Each element of the heap is an array with the cost and city
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, startCity});
        
        // Stores the travel cost reach each city from the start city
        vector<int> travelCosts(n, INT_MAX);
        long long minCost = LLONG_MAX;
        while (!minHeap.empty()){
            // Remove the city with the minimum cost from the top of the heap
            auto [travelCost, currCity] = minHeap.top();
            minHeap.pop();
            
            // Update the min cost if the curr city has a smaller total cost
            minCost = min(minCost, static_cast<long long>(appleCost[currCity] + travelCost * (k + 1)));
            
            // Add each neighboring city to the heap if an apple is cheaper
            for (auto& [neighbor, cost] : graph[currCity]){
                int nextCost = travelCost + cost;
                if (nextCost < travelCosts[neighbor]){
                    travelCosts[neighbor] = nextCost;
                    minHeap.push({nextCost, neighbor});
                }
            }
        }
        
        return minCost;
    }
    
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        this -> k = k, this -> n = n;
        
        // Add each road to the graph using adjacency lists
        // Sotre each city at graph[city - 1]
        for (vector<int>& road:roads){
            int start = road[0], end = road[1], cost = road[2];
            graph[start - 1].push_back({end - 1, cost});
            graph[end - 1].push_back({start - 1, cost});
        }
        
        // Find the minimum cost to buy an apple starting in each city
        vector<long long> ans(n);
        for (int startCity = 0; startCity < n; ++startCity)
            ans[startCity] = shortestPath(graph, appleCost, startCity);
        return ans;
    }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // Construct a graph from the given highways array
        vector<vector<pair<int, int>>> adj(n);
        
        for (vector<int>& highway : highways){
            int u = highway[0], v = highway[1], toll = highway[2];
            adj[u].push_back({v, toll});
            adj[v].push_back({u, toll});
        }
        
        // 2D array to track minimum distance to each city with a given number of discounts used
        vector dist(n, vector<int>(discounts + 1, INT_MAX));
        vector visited(n, vector<bool>(discounts + 1, false));
        dist[0][0] = 0;
        
        // Min-heap priority queue to store vectors of (cost, city, used discounts)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        // Start from city 0 with cost 0 and 0 discounts used
        pq.push(make_tuple(0, 0, 0));
        
        while (!pq.empty()){
            int currCost, city, usedDiscounts;
            tie(currCost, city, usedDiscounts) = pq.top(); pq.pop();
            
            // Skip processing if already visited with the same number of discounts used
            if (visited[city][usedDiscounts])
                continue;
            
            visited[city][usedDiscounts] = true;
            
            // Explore all neighbors of the current city
            for (auto& [neighbor, toll] : adj[city]){
                // Case 1: Move to the neighbor without using a discount
                if (currCost + toll < dist[neighbor][usedDiscounts]){
                    dist[neighbor][usedDiscounts] = currCost + toll;
                    pq.push(make_tuple(currCost + toll, neighbor, usedDiscounts));
                }
                
                // Case 2: Move to the neighbor using a discount if available
                if (usedDiscounts < discounts){
                    int newCost = currCost + (toll >> 1);
                    if (newCost < dist[neighbor][usedDiscounts + 1]){
                        dist[neighbor][usedDiscounts + 1] = newCost;
                        pq.push(make_tuple(newCost, neighbor, usedDiscounts + 1));
                    }
                }
            }
        }
        
        // Find the minimum cost to reach city n - 1 with any number of discounts used
        int minCost = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        return (minCost == INT_MAX)? -1 : minCost;
    }
};
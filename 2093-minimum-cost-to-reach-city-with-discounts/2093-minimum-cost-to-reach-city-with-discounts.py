class Solution:
    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
        # Construct the graph from the given highways array
        adj = [[] for _ in range(n)]
        
        for u, v, toll in highways:
            adj[u].append((v, toll))
            adj[v].append((u, toll))
            
        # Min-heap priority queue to store tuples of (cost, city, used_discounts)
        pq = [(0, 0, 0)] # Start from city 0 with cost 0 and 0 discounts used
        
        # 2D array to track minimum distance to each city with a given number of discounts used
        dist = [[float("inf")] * (discounts + 1) for _ in range(n)]
        dist[0][0] = 0
        
        while pq:
            curr_cost, city, used_discounts = heappop(pq)
            
            # If this cost is already higher than the known minimum, skip it
            if curr_cost > dist[city][used_discounts]:
                continue
                
            # Explore all neighbors of the current city
            for neighbor, toll in adj[city]:
                # Case 1: Move to the neighbor without using a discount
                if curr_cost + toll < dist[neighbor][used_discounts]:
                    dist[neighbor][used_discounts] = curr_cost + toll
                    heappush(pq, (dist[neighbor][used_discounts], neighbor, used_discounts))
                    
                # Case 2: Move to the neighbor using a discount if available
                if used_discounts < discounts:
                    new_cost = curr_cost + (toll >> 1)
                    
                    if new_cost < dist[neighbor][used_discounts + 1]:
                        dist[neighbor][used_discounts + 1] = new_cost
                        heappush(pq, (new_cost, neighbor, used_discounts + 1))
            
        # Find the minimum cost to reach city n - 1 with any number of discounts used
        min_cost = min(dist[n - 1])
        return -1 if min_cost == float("inf") else min_cost
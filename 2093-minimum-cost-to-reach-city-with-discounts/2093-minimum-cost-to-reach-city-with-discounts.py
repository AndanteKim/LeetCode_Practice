class Solution:
    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
        # Construct the graph from the given highways array
        adj = [[] for _ in range(n)]
        
        for u, v, toll in highways:
            adj[u].append((v, toll))
            adj[v].append((u, toll))
            
        # Min-heap priority qyeye to store tuples of (cost, city, discounts used)
        pq = [(0, 0, 0)]
        
        # 2D array to track minimum distance to each city with a given number of discounts used
        dist = [[float("inf")] * (discounts + 1) for _ in range(n)]
        dist[0][0] = 0
        
        visited = [[False] * (discounts + 1) for _ in range(n)]
        
        while pq:
            curr_cost, city, used = heappop(pq)
            
            # Skip processing if already visited with the same number of discounts used
            if visited[city][used]:
                continue
            
            visited[city][used] = True
            
            # Explore all neighbors of the current city
            for neighbor, toll in adj[city]:
                # Case 1: Move to the neighbor without using a discount
                if curr_cost + toll < dist[neighbor][used]:
                    dist[neighbor][used] = curr_cost + toll
                    heappush(pq, (dist[neighbor][used], neighbor, used))
                    
                # Case 2: Move to the neighbor using a discount if available
                if used < discounts:
                    discounted_cost  = curr_cost + (toll >> 1)
                    if discounted_cost < dist[neighbor][used + 1]:
                        dist[neighbor][used + 1] = discounted_cost
                        heappush(pq, (discounted_cost, neighbor, used + 1))
                
        # Find the minimum cost to reach city n - 1 with any number of discounts used
        min_cost = min(dist[n - 1])
        
        return -1 if min_cost == float("inf") else min_cost
        
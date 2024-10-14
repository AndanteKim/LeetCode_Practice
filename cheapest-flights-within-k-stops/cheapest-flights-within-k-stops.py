class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = defaultdict(list)
        
        for start, end, cost in flights:
            adj[start].append((end, cost))
            
        stops = [float('inf')] * n
        pq = [(0, src, 0)]
        
        while pq:
            dist, node, steps = heappop(pq)
            
            # We've already encountered a path with a lower cost and few stops,
            # or the number of stops exceed the limit.
            if steps > stops[node] or steps > k + 1:
                continue
            
            stops[node] = steps
            if node == dst:
                return dist
            
            for neighbor, cost in adj[node]:
                heappush(pq, (dist + cost, neighbor, steps + 1))
        
        return -1
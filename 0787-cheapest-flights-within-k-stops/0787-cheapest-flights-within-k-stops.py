class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = defaultdict(list[list])
        
        for e in flights:
            adj[e[0]].append([e[1], e[2]])
            
        stops = [float('inf')] * n
        pq = [(0, src, 0)]
        
        while pq:
            temp = heapq.heappop(pq)
            dist, node, steps = temp[0], temp[1], temp[2]
            
            if steps > stops[node] or steps > k + 1: continue
            
            stops[node] = steps
            if node == dst: return dist
            
            for neighbor, price in adj[node]:
                heapq.heappush(pq, (dist + price, neighbor, steps + 1))
        return -1
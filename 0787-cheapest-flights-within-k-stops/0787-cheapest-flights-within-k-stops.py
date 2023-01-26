class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = defaultdict(list[list])
        for edge in flights:
            adj[edge[0]].append([edge[1], edge[2]])
        
        dist = [float('inf')] * n
        q, stops = deque([(src, 0)]), 0
        
        while (stops <= k and q):
            sz = len(q)
            while sz:
                node, distance = q.popleft()
                
                for neighbor, price in adj[node]:
                    if price + distance >= dist[neighbor]: continue
                    dist[neighbor] = price + distance
                    q.append((neighbor, dist[neighbor]))
                sz -= 1
            stops += 1
        
        return -1 if dist[dst] == float('inf') else dist[dst]
        
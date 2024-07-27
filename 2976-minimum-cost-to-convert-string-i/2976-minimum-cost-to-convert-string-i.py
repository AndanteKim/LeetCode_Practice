class Solution:
    def dijkstra(self, origin: chr, adj: DefaultDict[chr, Tuple[chr, int]], distances: List[int]) -> None:
        pq = [(0, origin)]
        
        while pq:
            curr_cost, c = heappop(pq)
            
            if curr_cost > distances[ord(c) - 97]:
                continue
                
            for neighbor, cost in adj[c]:
                if curr_cost + cost < distances[ord(neighbor) - 97]:
                    distances[ord(neighbor) - 97] = curr_cost + cost
                    heappush(pq, (curr_cost + cost, neighbor))
    
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        adj = defaultdict(list)
        matrix = [[float('inf')] * 26 for _ in range(26)]
        for i in range(26):
            matrix[i][i] = 0
        
        for i in range(len(original)):
            adj[original[i]].append((changed[i], cost[i]))
        
        for i in range(26):
            self.dijkstra(chr(i + 97), adj, matrix[i])
            
        ans = 0
        for i in range(len(source)):
            if matrix[ord(source[i]) - 97][ord(target[i]) - 97] == float("inf"):
                return -1
            
            ans += matrix[ord(source[i]) - 97][ord(target[i]) - 97]
        
        return ans
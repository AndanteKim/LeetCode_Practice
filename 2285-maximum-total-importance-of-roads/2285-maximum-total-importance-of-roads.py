class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        
        for start, end in roads:
            adj[start].append(end)
            adj[end].append(start)
            
        pairs = []
        for node in adj:
            heappush(pairs, (-len(adj[node]), node))
        
        val, importance = n, [0] * n
        while pairs and val >= 1:
            importance[heappop(pairs)[1]] = val
            val -= 1
        
        ans, visited = 0, [False] * n
        
        for node in range(n):
            if not visited[node]:
                visited[node] = True
                
                for neighbor in adj[node]:
                    ans += importance[node] + importance[neighbor]
                    
        return ans >> 1
class Solution:
    answer = float('inf')
    def dfs(self, node: int, adj: List[List[int]], visit: List[bool]):
        visit[node] = True
        for edge in adj[node]:
            self.answer = min(self.answer, edge[1])
            if not visit[edge[0]]:
                self.dfs(edge[0], adj, visit)
    
    
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = [[] for _ in range(n+1)]
        
        for road in roads:
            adj[road[0]].append([road[1], road[2]])
            adj[road[1]].append([road[0], road[2]])
        
        visit = [False] * (n + 1)
        self.dfs(1, adj, visit)
        
        return self.answer
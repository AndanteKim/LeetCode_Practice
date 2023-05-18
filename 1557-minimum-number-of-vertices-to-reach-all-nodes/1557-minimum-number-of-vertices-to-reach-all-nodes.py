class Solution:
    def dfs(self, node: int, start: int, visited: List[int], adj: List[List[int]]) -> None:
        if not visited[node]:
            if node != start:
                visited[node] = True
            for neighbor in adj[node]:
                self.dfs(neighbor, start, visited, adj)
    
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        
        for start, end in edges:
            adj[start].append(end)
        
        visited = [False] * n
        
        for node in range(n):
            self.dfs(node, node, visited, adj)
        
        return [node for node in range(n) if not visited[node]]
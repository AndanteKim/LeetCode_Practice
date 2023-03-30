class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool]) -> None:
        visited[node] = True
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited)
        
    
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        adj = [[] for _ in range(n)]
        visited = [False] * n
        for start, end in edges:
            adj[start].append(end)
            adj[end].append(start)
        
        self.dfs(source, adj, visited)
        return visited[destination]
        
        
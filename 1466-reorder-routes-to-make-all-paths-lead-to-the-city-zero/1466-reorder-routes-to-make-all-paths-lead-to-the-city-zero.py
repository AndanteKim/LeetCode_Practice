class Solution:
    def dfs(self, node: int, adj: List[List[Tuple[int, int]]], visited: List[bool]) -> None:
        visited[node] = True
        
        for neighbor, score in adj[node]:
            if not visited[neighbor]:
                self.ans += score
                self.dfs(neighbor, adj, visited)
    
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        
        for start, end in connections:
            adj[start].append((end, 1))
            adj[end].append((start, 0))
        
        visited, self.ans = [False] * n, 0
        
        for node in range(n):
            if not visited[node]:
                self.dfs(node, adj, visited)
        return self.ans
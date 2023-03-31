class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool]):
        visited[node] = True
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited)
    
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj, visited, ans = [[] for _ in range(n)], [False] * n, 0
        
        for start, end in edges:
            adj[start].append(end)
            adj[end].append(start)
            
        for node in range(n):
            if not visited[node]:
                self.dfs(node, adj, visited)
                ans += 1
            
        return ans
        
        
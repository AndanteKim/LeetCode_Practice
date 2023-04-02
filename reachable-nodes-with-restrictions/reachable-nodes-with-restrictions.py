class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool]) -> None:
        visited[node] = True
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited)
    
    
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        visited, adj = [False] * n, [[] for _ in range(n)]
        filtered = [False] * n
        for node in restricted:
            filtered[node] = True
        
        for start, end in edges:
            if filtered[start] or filtered[end]:
                continue
            adj[start].append(end)
            adj[end].append(start)
        
        self.dfs(0, adj, visited)
        
        return visited.count(True)
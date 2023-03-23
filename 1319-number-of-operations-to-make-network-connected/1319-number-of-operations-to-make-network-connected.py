class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool]) -> None:
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited)
    
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        
        adj, visited = [[] for _ in range(n)], [False] * n
        for connection in connections:
            adj[connection[0]].append(connection[1])
            adj[connection[1]].append(connection[0])
        
        connected = 0
        for i in range(n):
            if not visited[i]:
                connected += 1
                self.dfs(i, adj, visited)
        
        return connected - 1
        
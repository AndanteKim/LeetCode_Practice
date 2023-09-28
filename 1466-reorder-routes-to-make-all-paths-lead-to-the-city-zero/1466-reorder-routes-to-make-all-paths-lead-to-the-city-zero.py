class Solution:
    def bfs(self, start: int, n: int, adj: List[List[int]]) -> None:
        queue = deque([start])
        visited = [False] * n
        visited[start] = True
        
        while queue:
            node = queue.popleft()
            
            for neighbor, sign in adj[node]:
                if not visited[neighbor]:
                    self.ans += sign
                    queue.append(neighbor)
                    visited[neighbor] = True
                
    
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj, self.ans = [[] for _ in range(n)], 0
        
        for start, end in connections:
            adj[start].append((end, 1))
            adj[end].append((start, 0))
            
        self.bfs(0, n, adj)
        
        return self.ans
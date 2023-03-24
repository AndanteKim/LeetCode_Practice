class Solution:
    count = 0
    
    def bfs(self, node: int, n: int, adj: List[Tuple[int]]) -> None:
        queue = deque([node])
        visited = [False] * n
        visited[node] = True
        
        while queue:
            curr_node = queue.popleft()
            
            for neighbor, sign in adj[curr_node]:
                if not visited[neighbor]:
                    self.count += sign
                    visited[neighbor] = True
                    queue.append(neighbor)
    
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        
        for start, end in connections:
            adj[start].append((end, 1))
            adj[end].append((start, 0))
        
        self.bfs(0, n, adj)
        
        return self.count
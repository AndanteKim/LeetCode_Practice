class Solution:
    count = 0
    
    def dfs(self, node: int, parent: int, adj: List[Tuple[int]]) -> None:
        for child, sign in adj[node]:
            if child != parent:
                self.count += sign
                self.dfs(child, node, adj)
    
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        
        for start, end in connections:
            adj[start].append((end, 1))
            adj[end].append((start, 0))
            
        self.dfs(0, -1, adj)
        return self.count
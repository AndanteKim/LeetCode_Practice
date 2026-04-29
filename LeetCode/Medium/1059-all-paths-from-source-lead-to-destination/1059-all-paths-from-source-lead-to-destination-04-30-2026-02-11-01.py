class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        def dfs(node: int) -> bool:
            if node == destination:
                return True
            
            if node in visited:
                return visited[node]
            
            visited[node] = False
            if len(adj[node]) == 0:
                return False
            
            for nxt in adj[node]:
                if not dfs(nxt):
                    return False
            visited[node] = True
            return visited[node]
        
        visited, adj = dict(), defaultdict(list)
        
        for u, v in edges:
            adj[u].append(v)

        if len(adj[destination]) > 0:
            return False
        
        return dfs(source)
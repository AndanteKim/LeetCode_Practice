class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        def dfs(node: int, parent: int) -> int:
            if node in seen:
                return False
            
            seen.add(node)
            for neighbor in graph[node]:
                if neighbor == parent:
                    continue
                
                if neighbor in seen or not dfs(neighbor, node):
                    return False

            return True
        
        if len(edges) != n - 1:
            return False
        
        graph = [[] for _ in range(n)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        seen = set()

        return dfs(0, -1) and len(seen) == n
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        def dfs(node: int) -> None:
            if visited[node]:
                return
            
            visited[node] = True
            for neighbor in graph[node]:
                dfs(neighbor)
        
        ans, graph = 0, [[] for _ in range(n)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        for node in range(n):
            if visited[node]:
                continue
            ans += 1
            dfs(node)
        return ans
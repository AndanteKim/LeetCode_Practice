class Solution:
    def dfs(self, node: int, nodes: int, bombs: List[List[int]], visited: List[bool]) -> None:
        if not visited[node]:
            visited[node] = True
            x_i, y_i, r_i = bombs[node]
            for neighbor in range(nodes):
                if visited[neighbor]:
                    continue
                if ((x_i - bombs[neighbor][0]) ** 2 + (y_i - bombs[neighbor][1]) ** 2) <= r_i ** 2:
                    self.dfs(neighbor, nodes, bombs, visited)
    
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        ans, n = 0, len(bombs)
        for node in range(n):
            visited = [False] * n
            self.dfs(node, n, bombs, visited)
            ans = max(ans, visited.count(True))
        
        return ans
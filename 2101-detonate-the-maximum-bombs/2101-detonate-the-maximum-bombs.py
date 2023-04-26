class Solution:
    def isOverlapped(self, s_x: int, s_y: int, s_r: int, n_x: int, n_y: int, n_r: int) -> bool:
        return (n_x - s_x) ** 2 + (n_y - s_y) ** 2 <= s_r ** 2
    
    def dfs(self, n: int, origin: int, start: int, visited: List[int], bombs: List[List[int]]) -> int:
        visited[start] = True
        for neighbor in range(n):
            if visited[neighbor]:
                continue
            start_x, start_y, start_r = bombs[start]
            neighbor_x, neighbor_y, neighbor_r = bombs[neighbor]
            
            if self.isOverlapped(start_x, start_y, start_r, neighbor_x, neighbor_y, neighbor_r):
                self.dfs(n, origin, neighbor, visited, bombs)
    
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n, ans = len(bombs), 0
        for node in range(n):
            visited = [False] * n
            visited[node] = True
            self.dfs(n, node, node, visited, bombs)
            ans = max(ans, visited.count(True))
        return ans
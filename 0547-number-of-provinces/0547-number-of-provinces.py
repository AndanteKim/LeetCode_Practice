class Solution:
    def dfs(self, node: int, isConnected: List[List[int]], visited: List[bool]) -> None:
        visited[node] = True
        for neighbor in range(len(isConnected[node])):
            if node != neighbor and isConnected[node][neighbor] != 0 and not visited[neighbor]:
                self.dfs(neighbor, isConnected, visited)
    
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited, ans = [False] * len(isConnected), 0
        for node in range(len(isConnected)):
            if not visited[node]:
                self.dfs(node, isConnected, visited)
                ans += 1
            
                
        return ans
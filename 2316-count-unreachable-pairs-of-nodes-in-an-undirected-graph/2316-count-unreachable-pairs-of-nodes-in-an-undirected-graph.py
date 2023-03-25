class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool]) -> None:
        count = 1
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                count += self.dfs(neighbor, adj, visited)
        return count
    
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        
        for start, end in edges:
            adj[start].append(end)
            adj[end].append(start)
            
        numberOfPairs, sizeOfComponent, remainingNodes = 0, 0, n
        visited = [False] * n
        
        for node in range(n):
            if not visited[node]:
                sizeOfComponent = self.dfs(node, adj, visited)
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent)
                remainingNodes -= sizeOfComponent
            
        return numberOfPairs
            
        
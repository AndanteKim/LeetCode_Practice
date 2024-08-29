class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        # DFS to visit all stones in a connected component
        def dfs(stone: int) -> None:
            visited[stone] = True
            
            for neighbor in adj[stone]:
                if not visited[neighbor]:
                    dfs(neighbor)
        
        n = len(stones)
        
        # Adjacency list to store graph connections
        adj = [[] for _ in range(n)]
        
        # Build the graph: Connect stones sharing the same row or column.
        for i in range(n):
            for j in range(i + 1, n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    adj[i].append(j)
                    adj[j].append(i)
                    
        num_of_connected_components, visited = 0, [False] * n
        
        # Traverse all stones using DFS to count connected components
        for i in range(n):
            if not visited[i]:
                dfs(i)
                num_of_connected_components += 1
        
        # Maximum stones that can be removed is total stones - number of connected components
        return n - num_of_connected_components
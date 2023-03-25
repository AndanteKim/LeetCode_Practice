class Solution:
    def bfs(self, node: int, adj: List[List[int]], visited: List[bool]) -> int:
        visited[node], count = True, 1
        queue = deque([node])
        
        while queue:
            curr_node = queue.popleft()
            for neighbor in adj[curr_node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    count += 1
                    queue.append(neighbor)
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
                sizeOfComponent = self.bfs(node, adj, visited)
                numberOfPairs += sizeOfComponent * (remainingNodes - sizeOfComponent)
                remainingNodes -= sizeOfComponent
        
        return numberOfPairs
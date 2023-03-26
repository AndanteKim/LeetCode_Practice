class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        visited, indegree = [False] * n, [0] * n
        
        for edge in edges:
            if edge != -1:
                indegree[edge] += 1
        
        queue = deque()
        for node in range(n):
            if indegree[node] == 0:
                queue.append(node)
            
        while queue:
            node = queue.popleft()
            visited[node] = True
            neighbor = edges[node]
            if neighbor != -1:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        ans = -1
        
        for node in range(n):
            if not visited[node]:
                neighbor = edges[node]
                count = 1
                visited[node] = True
                
                while neighbor != node:
                    visited[neighbor] = True
                    count += 1
                    neighbor = edges[neighbor]
                ans = max(ans, count)
        return ans
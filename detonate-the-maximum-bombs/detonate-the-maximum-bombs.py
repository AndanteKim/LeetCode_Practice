class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        graph, n = defaultdict(list), len(bombs)
        # Make the graph
        for i in range(n - 1):
            x1, y1, r1 = bombs[i]
            for j in range(i + 1, n):
                x2, y2, r2 = bombs[j]
                influence = ((abs(x1 - x2) ** 2 + abs(y1 - y2) ** 2) ** 0.5)
                if influence <= r1:
                    graph[i].append(j)
                
                if influence <= r2:
                    graph[j].append(i)
        
        ans = 0
        for i in range(n):
            visited, exploded = [False] * n, 0
            visited[i], queue = True, deque([i])
            
            while queue:
                node = queue.popleft()
                
                exploded += 1
                for neighbor in graph[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True 
                        queue.append(neighbor)
            ans = max(ans, exploded)
            
        return ans
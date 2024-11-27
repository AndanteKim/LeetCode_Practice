class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph, ans = defaultdict(list), [0] * len(queries)
        
        for i in range(n - 1):
            graph[i].append(i + 1)
            
        for i, (start, end) in enumerate(queries):
            graph[start].append(end)
            
            visited, dijkstra = [float('inf')] * n, [(0, 0)]
            
            while dijkstra:
                steps, node = heappop(dijkstra)
                
                if steps >= visited[node]:
                    continue
                
                if node == n - 1:
                    ans[i] = steps
                    break
                
                visited[node] = steps
                for neighbor in graph[node]:
                    heappush(dijkstra, (steps + 1, neighbor))
                    
        return ans
class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(list)

        for u, v, cost in roads:
            graph[u].append((v, cost))
            graph[v].append((u, cost))
        
        visited = [False] * (n + 1)
        queue, ans = deque([1]), float('inf')
        visited[1] = True

        while queue:
            node = queue.popleft()

            for neighbor, cost in graph[node]:
                ans = min(ans, cost)
                if visited[neighbor]:
                    continue
                queue.append(neighbor)
                visited[neighbor] = True
        
        return ans
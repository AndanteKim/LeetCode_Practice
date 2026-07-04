class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        def dfs(node: int) -> None:
            for neighbor, cost in graph[node]:
                self.ans = min(self.ans, cost)
                if visited[neighbor]:
                    continue
                visited[neighbor] = True
                dfs(neighbor)

        graph = defaultdict(list)

        for u, v, dist in roads:
            graph[u].append((v, dist))
            graph[v].append((u, dist))

        self.ans, visited = float('inf'), [False] * (n + 1)
        dfs(1)
        return self.ans
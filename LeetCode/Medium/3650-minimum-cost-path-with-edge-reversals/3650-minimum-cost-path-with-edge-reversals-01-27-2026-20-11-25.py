class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        neighbors = [[] for _ in range(n)]

        for u, v, w in edges:
            neighbors[u].append((v, w))
            neighbors[v].append((u, 2 * w))

        dist, visited = [float('inf')] * n, [False] * n
        dist[0] = 0
        pq = [(0, 0)]

        while pq:
            cost, u = heappop(pq)

            if u == n - 1:
                return cost

            if visited[u]:
                continue
            
            visited[u] = True

            # expand neighbors
            for v, w in neighbors[u]:
                new_cost = cost + w
                if new_cost < dist[v]:
                    dist[v] = new_cost
                    heappush(pq, (new_cost, v))

        return -1
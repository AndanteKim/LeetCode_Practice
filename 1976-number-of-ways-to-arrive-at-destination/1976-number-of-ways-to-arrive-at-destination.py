class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph, mod = [[] for _ in range(n)], 10 ** 9 + 7

        # Build adjacency list
        for u, v, time in roads:
            graph[u].append((v, time))
            graph[v].append((u, time))
        
        # Min-Heap (priority queue) for Dijkstra
        min_heap = [(0, 0)] # (time, node)
        # Store the shortest time to each node
        shortest_time = [float('inf')] * n
        # Number of ways to reach each node in the shortest time
        path_count = [0] * n
        
        shortest_time[0] = 0    # Distance to source is 0
        path_count[0] = 1   # 1 way to reach node 0
        
        while min_heap:
            t, curr_node = heappop(min_heap)

            # Skip outdated distances
            if t > shortest_time[curr_node]:
                continue

            for neighbor, run_time in graph[curr_node]:
                # Found a new shortest path → Update the shortest time and reset path count
                if t + run_time < shortest_time[neighbor]:
                    shortest_time[neighbor] = t + run_time
                    path_count[neighbor] = path_count[curr_node]
                    heappush(min_heap, (shortest_time[neighbor], neighbor))

                # Found another way with the same shortest time → Add to path count
                elif t + run_time == shortest_time[neighbor]:
                    path_count[neighbor] = (path_count[neighbor] + path_count[curr_node]) % mod
        
        return path_count[n - 1]
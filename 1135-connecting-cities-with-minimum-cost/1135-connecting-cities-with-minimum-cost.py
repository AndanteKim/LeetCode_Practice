class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        graph = [[] for _ in range(n + 1)]

        for x, y, cost in connections:
            graph[x].append((y, cost))
            graph[y].append((x, cost))
        
        # Prim algorithm
        mst, next_nodes = set(), [(0, 1)]
        min_cost = 0

        while len(mst) != n:
            if not next_nodes:
                return -1
            cost, node = heappop(next_nodes)
            if node in mst:
                continue
            min_cost += cost
            mst.add(node)

            for next_node, next_cost in graph[node]:
                if next_node in mst:
                    continue
                heappush(next_nodes, (next_cost, next_node))

        return min_cost
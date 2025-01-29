class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Perform the DFS and store a node in the cycle s cycle_start
        def dfs(src: int) -> None:
            visited[src] = True

            for adj in adj_list[src]:
                if not visited[adj]:
                    parent[adj] = src
                    dfs(adj)
                
                # If the node is visited and the parent is different then the node
                # is part of the cycle.
                elif adj != parent[src] and self.cycle_start == -1:
                    self.cycle_start, parent[adj] = adj, src
        
        self.cycle_start, n = -1, len(edges)
        visited, parent = [False] * n, [-1] * n
        adj_list = [[] for _ in range(n)]

        for u, v in edges:
            adj_list[u - 1].append(v - 1)
            adj_list[v - 1].append(u - 1)

        dfs(0)
        cycle_nodes, node = dict(), self.cycle_start

        # Start from the cycle_start node and backtrack to get all the nodes in the cycle.
        # Mark them all in the map.
        while True:
            cycle_nodes[node] = 1
            node = parent[node]
            if node == self.cycle_start:
                break
        
        # If both nodes of the edge were marked as cycle nodes then this edge
        # can be removed
        for i in range(n - 1, -1, -1):
            if (edges[i][0] - 1) in cycle_nodes and (edges[i][1] - 1) in cycle_nodes:
                return edges[i]

        return []   # This line should theoretically never be reached.
        
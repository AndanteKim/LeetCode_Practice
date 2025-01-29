class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Performs DFS and returns True if there's a path between src and target
        def _is_connected(src: int, target: int, visited: List[bool], adj_list: List[List[bool]]) -> bool:
            visited[src] = True

            if src == target:
                return True
            
            is_found = False
            for adj in adj_list[src]:
                if not visited[adj]:
                    is_found = is_found or _is_connected(adj, target, visited, adj_list)

            return is_found
        
        n = len(edges)
        adj_list = [[] for _ in range(n)]

        for edge in edges:
            visited = [False] * n

            # If DFS returns True, we'll return the edge
            if _is_connected(edge[0] - 1, edge[1] - 1, visited, adj_list):
                return edge

            adj_list[edge[0] - 1].append(edge[1] - 1)
            adj_list[edge[1] - 1].append(edge[0] - 1)

        return []
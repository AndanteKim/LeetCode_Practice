class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        def dp(node: int, mask: int) -> int:
            state = (node, mask)
            if state in cache:
                return cache[state]
            
            if mask & (mask - 1) == 0:
                # base case mask only has a single "1" meaning that
                # only one node has been visited (the current node)
                return 0
            
            cache[state] = float('inf') # avoid infinite loop in recursion
            for neighbor in graph[node]:
                if mask & (1 << neighbor):
                    already_visited = 1 + dp(neighbor, mask)
                    not_visited = 1 + dp(neighbor, mask ^ (1 << node))
                    cache[state] = min(cache[state], already_visited, not_visited)
            
            return cache[state]
        
        
        n = len(graph)
        ending_mask = (1 << n) - 1
        cache = dict()
        
        return min(dp(node, ending_mask) for node in range(n))
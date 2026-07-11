class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        def _dfs(curr: int, info: List[int, int]) -> None:
            visited.add(curr)
            info[0] += 1    
            info[1] += len(graph[curr])

            for nxt_v in graph[curr]:
                if nxt_v not in visited:
                    _dfs(nxt_v, info)
        
        graph = defaultdict(list)

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        complete_count = 0
        visited = set()

        for v in range(n):
            if v in visited:
                continue
            
            component_info = [0, 0]
            _dfs(v, component_info)
        
            if component_info[0] * (component_info[0] - 1) == component_info[1]:
                complete_count += 1

        return complete_count
class Solution:
    def dfs(self, node: int, visited: Dict[int, int], graph: Dict[int, List[int]]) -> int:
        # return the longest path(inclusive)
        if node in visited:
            return visited[node]
        else:
            # mark as visiting
            visited[node] = -1
        
        max_length = 1
        for end_node in graph[node]:
            length = self.dfs(end_node, visited, graph)
            # we meet a cycle!
            if length == -1:
                return -1
            else:
                max_length = max(length + 1, max_length)
        
        # mark as visited
        visited[node] = max_length
        return max_length
    
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        graph = {i : [] for i in range(1, n + 1)}
        for start_node, end_node in relations:
            graph[start_node].append(end_node)
            
        visited, max_length = dict(), -1
        for node in graph.keys():
            length = self.dfs(node, visited, graph)
            # we meet a cycle
            if length == -1:
                return -1
            else:
                max_length = max(length, max_length)
        
        return max_length
        
        
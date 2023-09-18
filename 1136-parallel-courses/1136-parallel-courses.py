class Solution:
    def dfs_check_cycle(self, node: int, visited: Dict[int, int], graph: Dict[int, List[int]]) -> bool:
        # return True if graph has a cycle
        if node in visited:
            return visited[node]
        else:
            # mark as visiting
            visited[node] = -1
        for end_node in graph[node]:
            if self.dfs_check_cycle(end_node, visited, graph):
                # we meet a cycle
                return True
        # mark as visited
        visited[node] = False
        return False
    
    def dfs_max_path(self, node: int, visited_length: Dict[int, int], graph: Dict[int, List[int]]) -> int:
        # return the longest path (inclusive)
        if node in visited_length:
            return visited_length[node]
        max_length = 1
        for end_node in graph[node]:
            length = self.dfs_max_path(end_node, visited_length, graph)
            max_length = max(length + 1, max_length)
        
        # store it
        visited_length[node] = max_length
        return max_length
    
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        graph = {i : [] for i in range(1, n + 1)}
        
        for start_node, end_node in relations:
            graph[start_node].append(end_node)
        
        # check if the graph contains a cycle
        visited = dict()
        
        # If having cycle, return -1
        for node in graph.keys():
            if self.dfs_check_cycle(node, visited, graph):
                return -1
        
        # if no cycle, return the longest path
        visited_length = dict()
        
        return max(self.dfs_max_path(node, visited_length, graph) for node in graph.keys())
        
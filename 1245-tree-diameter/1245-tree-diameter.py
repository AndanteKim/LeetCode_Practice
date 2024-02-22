class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        def bfs(start: int) -> Tuple[int]:
            """
            return the farthest node from the 'start' node
            and the distance between them.
            """
            visited = [False] * len(graph)
            
            visited[start] = True
            queue, dist = deque([start]), -1
            last_node = None
            
            while queue:
                next_queue = deque()
                while queue:
                    next_node = queue.popleft()
                    for neighbor in graph[next_node]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            next_queue.append(neighbor)
                            last_node = neighbor
                dist += 1
                queue = next_queue
            
            return last_node, dist
        
        if edges == []:
            return 0
        
        # build the adjacency list representation of the graph
        n = len(edges)
        graph = [set() for _ in range(n + 1)]
        
        for start, end in edges:
            graph[start].add(end)
            graph[end].add(start)
        
        # 1). find one of the farthest nodes
        farthest_node, dist_1 = bfs(0)
        
        # 2). find the other farthest node
        # and the distance between two farthest nodes
        another_farthest_node, dist_2 = bfs(farthest_node)
        
        return dist_2
            
            
        
        
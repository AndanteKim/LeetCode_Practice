class Solution:
    # Main function to calculate the maximum number of magnificent sets
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        # Checks if the graph is bipartite starting from the given node
        def _is_bipartite(node: int) -> bool:
            for neighbor in graph[node]:
                # If a neighbor has the same color as the current node, the graph isn't bipartite
                if colors[neighbor] == colors[node]:
                    return False
                
                # If the neighbor is already colored, skip it
                if colors[neighbor] != -1:
                    continue
                
                # Assign the opposite color to the neighbor
                colors[neighbor] = (colors[node] + 1) % 2

                # Recursively check bipartiteness for the neighbor; return false if it fails
                if not _is_bipartite(neighbor):
                    return False
            
            # If all neighbors are properly colored, return True
            return True

        # Compute the longest shortest path (height) in the graph starting from the source node
        def _get_longest_shortest_path(src_node: int, n: int) -> int:
            # Initialize a queue for BFS and a visited array
            queue = deque([src_node])
            visited = [False] * n
            dist, visited[src_node] = 0, True
            
            # Perform BFS layer by layer
            while queue:
                # Process all nodes in the current layer
                for _ in range(len(queue)):
                    curr_node = queue.popleft()
                    # Visit all unvisited neighbors of the current node
                    for neighbor in graph[curr_node]:
                        if visited[neighbor]:
                            continue
                        
                        visited[neighbor] = True
                        queue.append(neighbor)
                # Increment the distance for each layer
                dist += 1
            
            # Return the total distance (longest shortest path)
            return dist

        # Calculate the maximum number of groups for a connected component
        def _get_number_of_groups_for_component(node: int) -> int:
            # Start with the distance of the current node as the maximum
            max_number_of_groups = distances[node]
            visited[node] = True

            # Recursively calculate the maximum for all unvisited neighbors
            for neighbor in graph[node]:
                if visited[neighbor]:
                    continue
                max_number_of_groups = max(max_number_of_groups, _get_number_of_groups_for_component(neighbor))

            return max_number_of_groups
        
        # Create adjacency list for the graph
        graph = [[] for _ in range(n)]

        for u, v in edges:
            # Transition to 0-index
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)

        # Initialize color array to -1
        colors = [-1] * n

        # Check if the graph is bipartite
        for node in range(n):
            if colors[node] != -1:
                continue
            
            # Start coloring from uncolored nodes
            colors[node] = 0
            if not _is_bipartite(node):
                return -1
        
        # Calculate the longest shortest path for each node
        distances = [_get_longest_shortest_path(node, n) for node in range(n)]

        # Calculate the total maximum number of groups across all components
        max_number_of_groups = 0
        visited = [False] * n

        for node in range(n):
            if visited[node]:
                continue
            
            # Add the number of groups for this component to the total
            max_number_of_groups += _get_number_of_groups_for_component(node)

        return max_number_of_groups

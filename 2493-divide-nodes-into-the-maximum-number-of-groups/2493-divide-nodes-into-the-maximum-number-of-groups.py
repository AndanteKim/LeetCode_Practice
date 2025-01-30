class Solution:
    # Main function to calculate the maximum number of groups for the entire graph
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        self.n = n
        graph = [[] for _ in range(self.n)]
        parent, depth = [-1] * n, [0] * self.n

        # Build the adjacency list and apply Union-Find for each edge
        for u, v in edges:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)
            self._union(u - 1, v - 1, parent, depth)

        num_of_groups_for_component = dict()
    
        # For each node, calculate the maximum number of groups for its component
        for node in range(self.n):
            number_of_groups = self._get_number_of_groups(graph, node)
            
            if number_of_groups == -1:
                return -1       # If invalid split, return -1

            root_node = self._find(node, parent)
            num_of_groups_for_component[root_node] = max(num_of_groups_for_component.get(root_node, 0), number_of_groups)
        
        # Calculate the total number of groups across all components
        total_number_of_groups = sum(num_of_groups_for_component.values())
        return total_number_of_groups

    # Function to calculate the number of groups for a given component startig from src_node
    def _get_number_of_groups(self, graph: List[List[int]], src_node: int):
        queue = deque([src_node])
        layer_seen = [-1] * self.n
        layer_seen[src_node] = 0
        deepest_layer = 0

        # Perform BFS to calculate the number of layers (groups)
        while queue:
            sz = len(queue)
            for _ in range(sz):
                curr_node = queue.popleft()
                for neighbor in graph[curr_node]:
                    # If neighbor hasn't been visited, assign it to the next layer
                    if layer_seen[neighbor] == -1:
                        layer_seen[neighbor] = deepest_layer + 1
                        queue.append(neighbor)
                    else:
                        # If the neighbor is already in the same layer, return -1 (invalid partition)
                        if layer_seen[neighbor] == deepest_layer:
                            return -1
            deepest_layer += 1
        
        return deepest_layer
    
    # Find the root of the given node in the Union-Find structure
    def _find(self, node: int, parent: List[int]) -> int:
        while parent[node] != -1:
            node = parent[node]
        return node

    # Union operation to merge two sets
    def _union(self, node1: int, node2: int, parent: List[int], depth: List[int]) -> None:
        node1, node2 = self._find(node1, parent), self._find(node2, parent)

        # If the both nodes already belong to the same set, no action needed
        if node1 == node2:
            return

        # Union by rank (depth) to keep the tree balanced
        if depth[node1] < depth[node2]:
            node1, node2 = node2, node1
        parent[node2] = node1

        # If the depths are equal, increment the depth of the new root
        if depth[node1] == depth[node2]:
            depth[node1] += 1
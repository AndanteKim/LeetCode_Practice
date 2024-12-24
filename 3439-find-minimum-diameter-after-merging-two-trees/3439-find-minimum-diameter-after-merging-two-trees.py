class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        # Calculate the number of nodes for each tree
        n, m = len(edges1) + 1, len(edges2) + 1

        # Build adjacency lists for both trees
        adj_list1 = self.build_adj_list(n, edges1)
        adj_list2 = self.build_adj_list(m, edges2)

        # Calculate the diameters of both trees
        diameter1 = self.find_diameter(n, adj_list1)
        diameter2 = self.find_diameter(m, adj_list2)

        # Calculate the longest path spanning across both trees
        combined_diameter = ceil(diameter1 / 2) + ceil(diameter2 / 2) + 1

        # Return the maximim of the three possibilities
        return max(diameter1, diameter2, combined_diameter)

    def build_adj_list(self, size: int, edges: List[List[int]]) -> List[List[int]]:
        adj_list = [[] for _ in range(size)]

        for e1, e2 in edges:
            adj_list[e1].append(e2)
            adj_list[e2].append(e1)
        return adj_list

    def find_diameter(self, n: int, adj_list: List[List[int]]) -> int:
        # First BFS to find the farthest node from an arbitary node (e.g., 0)
        farthest_node, _ = self.find_farthest_node(n, adj_list, 0)

        # Second BFS to find the diameter starting from the farthest node
        _, diameter = self.find_farthest_node(n, adj_list, farthest_node)

        return diameter

    def find_farthest_node(self, n: int, adj_list: List[List[int]], source: int) -> Tuple[int, int]:
        queue = deque([source])
        visited = [False] * n
        visited[source] = True

        max_dist, farthest_node = 0, source

        while queue:
            for _ in range(len(queue)):
                curr_node = queue.popleft()
                farthest_node = curr_node

                for neighbor in adj_list[curr_node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append(neighbor)

            if queue:
                max_dist += 1
        
        return farthest_node, max_dist

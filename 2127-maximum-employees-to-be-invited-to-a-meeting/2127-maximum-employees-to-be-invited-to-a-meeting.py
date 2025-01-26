class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        # Calculate the maximum distance from a given start node
        def _bfs(start_node: int, visited_node: Set[int]) -> int:
            # Queue to store nodes and their distances
            queue = deque([(start_node, 0)])
            max_dist = 0

            while queue:
                curr_node, curr_dist = queue.popleft()
                for neighbor in reverse_graph[curr_node]:
                    if neighbor in visited_nodes:
                        continue    # Skip already visited nodes
                    visited_nodes.add(neighbor)
                    queue.append((neighbor, curr_dist + 1))
                    max_dist = max(max_dist, curr_dist + 1)
            
            return max_dist


        n = len(favorite)
        reverse_graph = [[] for _ in range(n)]

        # Build the reversed graph where each node points to its admirers
        for p in range(n):
            reverse_graph[favorite[p]].append(p)

        longest_cycle, two_cycle_invitations = 0, 0
        visited = [False] * n

        # Find all cycles in the graph
        for p in range(n):
            if not visited[p]:
                # Track visited people and their distance
                visited_people = dict()
                dist, curr_p = 0, p
                
                while True:
                    if visited[curr_p]:
                        break
                    visited[curr_p] = True
                    visited_people[curr_p] = dist
                    dist += 1
                    next_p = favorite[curr_p]

                    # Cycle detected
                    if next_p in visited_people:
                        cycle_length = dist - visited_people[next_p]
                        longest_cycle = max(longest_cycle, cycle_length)
                    
                        # Handle cycles of length 2
                        if cycle_length == 2:
                            visited_nodes = {curr_p, next_p}
                            two_cycle_invitations += (2 + _bfs(next_p, visited_nodes) + _bfs(curr_p, visited_nodes))
                        break
                    curr_p = next_p
            
        return max(longest_cycle, two_cycle_invitations)
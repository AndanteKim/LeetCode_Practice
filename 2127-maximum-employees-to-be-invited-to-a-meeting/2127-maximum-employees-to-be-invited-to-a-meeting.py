class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        indegree = [0] * n

        # Calculate in-degree for each node
        for p in range(n):
            indegree[favorite[p]] += 1

        # Topological sorting to remove non-cycle nodes
        q = deque()
        for p in range(n):
            if indegree[p] == 0:
                q.append(p)

        depth = [1] * n     # Depth of each node

        while q:
            curr_node = q.popleft()
            next_node = favorite[curr_node]

            depth[next_node] = max(depth[next_node], depth[curr_node] + 1)
            indegree[next_node] -= 1

            if indegree[next_node] == 0:
                q.append(next_node)

        longest_cycle, two_cycle_invitations = 0, 0

        # Detect cycles
        for p in range(n):
            if indegree[p] == 0:  # Already processed
                continue
            
            cycle_length, curr = 0, p

            while indegree[curr] != 0:
                indegree[curr] = 0  # Mark as visited
                cycle_length += 1
                curr = favorite[curr]

            if cycle_length == 2:
                # For 2-cycles, add the depth of both nodes
                two_cycle_invitations += depth[p] + depth[favorite[p]]
            else:
                longest_cycle = max(longest_cycle, cycle_length)

        return max(longest_cycle, two_cycle_invitations)
            

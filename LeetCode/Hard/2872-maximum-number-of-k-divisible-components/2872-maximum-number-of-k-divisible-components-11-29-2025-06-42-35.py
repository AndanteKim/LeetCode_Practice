class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        self.k = k

        # Step 1: Create adjacency list from edges
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # Step 2: Initialize component count
        component_count = [0]

        # Step 3: Start DFS traversal from node 0
        self.dfs(0, -1, adj, values, component_count)

        # Step 4: Return the total number of components
        return component_count[0]

    def dfs(self, curr_node: int, parent_node: int, adj: List[List[int]], node_values: List[int], component_count: List[int]) -> int:
        # Step 1: Initialize sum for the current subtree
        sum_ = 0

        # Step 2: Traverse all neighbors
        for neighbor in adj[curr_node]:
            if neighbor != parent_node:
                # Recursive call to process the subtree rooted at the neighbor
                sum_ += self.dfs(
                    neighbor,
                    curr_node,
                    adj,
                    node_values,
                    component_count
                )

                sum_ %= self.k
        
        # Step 3: Add the value of the current node to the sum
        sum_ += node_values[curr_node]
        sum_ %= self.k

        # Step 4: Check if the sum is divisible by k
        if sum_ == 0:
            component_count[0] += 1
    
        # Step 5: Return the computed sum for the current subtree
        return sum_
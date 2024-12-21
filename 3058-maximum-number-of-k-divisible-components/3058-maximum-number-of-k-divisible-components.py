class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        def dfs(curr_node: int, parent_node: int) -> int:
            # Step 1: Initialize sum for the current subtree
            _sum = 0
            
            # Step 2: Traverse all neighboors
            for neighbor in adj_list[curr_node]:
                if neighbor != parent_node:
                    # Recursive call to process the subtree rooted at the neighbor
                    _sum += dfs(neighbor, curr_node)
                    
                    _sum %= k   # Ensure the sum stays within bounds
                    
            # Step 3: Add the value of the current node to the sum
            _sum = (_sum + values[curr_node]) % k
            
            # Step 4: Check if the sum is divisible by k
            if _sum == 0:
                component_count[0] += 1
                
            # Step 5: Return the computed sum for the current subtree
            return _sum
        
        # Step 1: Create adjacency list from edges
        adj_list = [[] for _ in range(n)]
        
        for start, end in edges:
            adj_list[start].append(end)
            adj_list[end].append(start)
            
        # Step 2: Initialize component count
        component_count = [0]   # Use a list to pass by reference
        
        # Step 3: Start DFS traversal from node 0
        dfs(0, -1)
        
        # Step 4: Return the total number of components
        return component_count[0]
        
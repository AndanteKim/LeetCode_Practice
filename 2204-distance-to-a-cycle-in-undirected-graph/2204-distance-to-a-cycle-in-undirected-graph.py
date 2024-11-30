class Solution:
    # DFS to detect cycle nodes and mark them in 'is_in_cycle'
    def detect_cycle_nodes(self, curr_node: int, adj_list: List[List[int]], is_in_cycle: List[bool], visited: List[bool], parent: List[int]) -> bool:
        visited[curr_node] = True   # Mark current node as visited
        for nei in adj_list[curr_node]:
            if not visited[nei]:
                parent[nei] = curr_node     # Set parent for backtracking
                if self.detect_cycle_nodes(nei, adj_list, is_in_cycle, visited, parent):
                    return True     # Return True if cycle detected
            elif parent[curr_node] != nei:     # Cycle detected
                is_in_cycle[nei] = True    # Mark the start of the cycle
                temp_node = curr_node
                
                # Backtrack to mark all nodes in the cycle
                while temp_node != nei:
                    is_in_cycle[temp_node] = True
                    temp_node = parent[temp_node]
                return True
        return False    # No cycle found in this path
    
    # DFS to calculate distances from cycle nodes
    def calculate_dists(self, curr_node: int, curr_dist: int, adj_list: List[List[int]], dists: List[int], visited: List[bool], is_in_cycle: List[bool]) -> None:
        dists[curr_node] = curr_dist    # Set distance for current node
        visited[curr_node] = True       # Mark node as visited
        for nei in adj_list[curr_node]:
            if visited[nei]:
                continue    # Skip if already visited
            new_dist = 0 if is_in_cycle[nei] else curr_dist + 1    # Reset if on cycle
            
            self.calculate_dists(nei, new_dist, adj_list, dists, visited, is_in_cycle)
                    
       
    def distanceToCycle(self, n: int, edges: List[List[int]]) -> List[int]:
        is_in_cycle, visited = [False] * n, [False] * n
        parent, dists = [0] * n, [0] * n
        adj_list = [[] for _ in range(n)]
        
        # Build adjacency list for the graph
        for start, end in edges:
            adj_list[start].append(end)
            adj_list[end].append(start)
            
        # Detect and mark cycle nodes
        self.detect_cycle_nodes(0, adj_list, is_in_cycle, visited, parent)
        
        # Reset visited array before distance calculation
        visited = [False] * n
        
        # Calculate distances starting from any cycle node
        for i in range(n):
            if is_in_cycle[i]:
                self.calculate_dists(i, 0, adj_list, dists, visited, is_in_cycle)
                break   # Only need to start from one cycle node
                
        return dists
        
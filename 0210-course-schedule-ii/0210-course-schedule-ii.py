class Solution:
    WHITE, GRAY, BLACK = 1, 2, 3
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Create the adjacency list representation of the graph
        adj = [[] for _ in range(numCourses)]
        
        # A pair [a, b] in the input represents edges from b -> a
        for end, start in prerequisites:
            adj[start].append(end)
            
        # Topological order
        ans, is_possible = [], True
        
        # By default all vertices are WHITE
        color = {k : self.WHITE for k in range(numCourses)}
        
        def dfs(node: int) -> None:
            nonlocal is_possible
            
            # Don't recurse further if we found a cycle already
            if not is_possible:
                return
            
            # Start the recursion
            color[node] = self.GRAY
            
            # Traverse on neighboring vertices
            for neighbor in adj[node]:
                if color[neighbor] == self.WHITE:
                    dfs(neighbor)
                        
                elif color[neighbor] == self.GRAY:
                    # An edge to a GRAY vertex represents a cycle
                    is_possible = False
                        
            # Recursion ends. We mark it as black
            color[node] = self.BLACK
            ans.append(node)
            
        for vertex in range(numCourses):
            # If the node is unprocessed, then call dfs on it.
            if color[vertex] == self.WHITE:
                dfs(vertex)
        return ans[::-1] if is_possible else []
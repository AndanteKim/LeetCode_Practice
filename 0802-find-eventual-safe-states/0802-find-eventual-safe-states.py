class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        #
        def dfs(node: int) -> bool:
            # If the node is already in the stack, we have a cycle.
            if in_stack[node]:
                return True

            if visit[node]:
                return False
            
            # Mark the current node as visited and part of current recursion stack.
            visit[node], in_stack[node] = True, True

            for neighbor in graph[node]:
                if dfs(neighbor):
                    return True
            
            # Remove the node from the stack.
            in_stack[node] = False
            return False

        n = len(graph)
        visit, in_stack = [False] * n, [False] * n
        
        for node in range(n):
            dfs(node)
        
        ans = []
        for node in range(n):
            if not in_stack[node]:
                ans.append(node)
            
        return ans
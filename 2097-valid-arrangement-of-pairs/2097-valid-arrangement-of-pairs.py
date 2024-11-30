class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        def visit(node: int) -> None:
            while adj_mat[node]:
                next_node = adj_mat[node].popleft()
                visit(next_node)
            ans.append(node)
        
        adj_mat, in_degree, out_degree = defaultdict(deque), defaultdict(int), defaultdict(int)
        
        # Build the adjacency list and track in-degrees and out-degrees
        for start, end in pairs:
            adj_mat[start].append(end)
            out_degree[start] += 1
            in_degree[end] += 1
            
        ans = []
        
        # Find the start node (out_degree == 1 + in_degree)
        start_node = -1
        for node in out_degree:
            if out_degree[node] == in_degree[node] + 1:
                start_node = node
                break
                
        # If no such node exists, start from the first pair's first element
        if start_node == -1:
            start_node = pairs[0][0]
            
        # Start DFS traversal
        visit(start_node)
        
        # Reverse the result since DFS gives us the path in reverse
        ans.reverse()
        
        # Construct the result pairs
        paired_ans = [[ans[i - 1], ans[i]] for i in range(1, len(ans))]
        
        return paired_ans
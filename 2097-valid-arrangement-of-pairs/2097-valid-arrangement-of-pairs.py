class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        adj_mat = defaultdict(deque)
        in_degree, out_degree = defaultdict(int), defaultdict(int)
        
        # Build the adjacency list and track in-degrees and out-degrees
        for start, end in pairs:
            adj_mat[start].append(end)
            out_degree[start] += 1
            in_degree[end] += 1
        
        # Find the start node (out_degree = in_degree + 1)
        start_node = -1
        for node in out_degree:
            if out_degree[node] == in_degree[node] + 1:
                start_node = node
                break
        
        # If no such node exists, start from the first pair's first element
        if start_node == -1:
            start_node = pairs[0][0]
            
        # Iterative DFS using stack
        node_stack, res = [start_node], []
        
        while node_stack:
            node = node_stack[-1]
            if adj_mat[node]:
                # Visit the next node
                next_node = adj_mat[node].popleft()
                node_stack.append(next_node)
            else:
                # No more neighbors to visit, add node to result
                res.append(node)
                node_stack.pop()
        
        # Reverse the result since we collected nodes in reverse order
        res.reverse()
        
        # Construct the result pairs
        paired_res = []
        for i in range(1, len(res)):
            paired_res.append([res[i - 1], res[i]])
            
        return paired_res
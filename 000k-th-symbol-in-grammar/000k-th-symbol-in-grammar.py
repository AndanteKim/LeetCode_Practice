class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        def dfs(remain: int, pos: int, root_val: int) -> int:
            # Base case: If the row reached the target row
            if remain == 1:
                return root_val
            
            total_nodes = 2 ** (remain - 1)
            
            # Target node will be present in the right subtree of the current root node.
            if pos > (total_nodes >> 1):
                next_root_val = root_val ^ 1
                return dfs(remain - 1, pos - (total_nodes >> 1), next_root_val)
            # Otherwise, the target node is in the left subtree of the current root node.
            else:
                return dfs(remain - 1, pos, root_val)
        
        return dfs(n, k, 0)
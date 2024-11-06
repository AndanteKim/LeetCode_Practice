# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        # Depth-First search to calculate node depths and subtree heights
        def _dfs(node: TreeNode, level: int) -> int:
            if not node:
                return 0
            
            node_depths[node.val] = level
            
            # Calculate the height of the current subtree
            left_height = _dfs(node.left, level + 1)
            right_height = _dfs(node.right, level + 1)
            curr_height = 1 + max(left_height, right_height)
            
            subtree_heights[node.val] = curr_height
            
            # Update the largest and second largest heights at the current level
            if curr_height > first_largest_height.get(level, 0):
                second_largest_height[level] = first_largest_height.get(level, 0)
                first_largest_height[level] = curr_height
            elif curr_height > second_largest_height.get(level, 0):
                second_largest_height[level] = curr_height
            
            return curr_height
        
        # Dictionaries to store node depths and heights
        node_depths, subtree_heights = dict(), dict()
        
        # Dictionaries to store the first and second largest heights at each level
        first_largest_height, second_largest_height = dict(), dict()
        
        _dfs(root, 0)
        
        # Process each query
        q_size = len(queries)
        ans = [0] * q_size
        
        for i in range(q_size):
            query_node = queries[i]
            node_level = node_depths[query_node]
            if subtree_heights[query_node] == first_largest_height[node_level]:
                ans[i] = node_level + second_largest_height.get(node_level, 0) - 1
            else:
                ans[i] = node_level + first_largest_height.get(node_level, 0) - 1
        
        return ans
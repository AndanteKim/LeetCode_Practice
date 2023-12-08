# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        def dfs(node: Optional[TreeNode]) -> None:
            if not node:
                return
            
            dfs(node.left)
            dfs(node.right)
            descendant_sum[node] = descendant_sum[node.left] + descendant_sum[node.right] + node.val
            descendant_length[node] = descendant_length[node.left] + descendant_length[node.right] + 1
        
        descendant_sum, descendant_length = defaultdict(int), defaultdict(int)
        dfs(root)
        
        return max(descendant_sum[key] / descendant_length[key] for key in descendant_sum if descendant_length[key] != 0)
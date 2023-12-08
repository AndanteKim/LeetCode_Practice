# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        ans, stack, descendant_sum, descendant_length = 0.0, [[root, False]], defaultdict(int), defaultdict(int)
        
        while stack:
            node, visited = stack[-1]
            
            if visited:
                descendant_sum[node] = descendant_sum[node.left] + descendant_sum[node.right] + node.val
                descendant_length[node] = descendant_length[node.left] + descendant_length[node.right] + 1
                ans = max(ans, descendant_sum[node] / descendant_length[node])
                stack.pop()
                
            if not visited:
                stack[-1][1] = True
                if node.right:
                    stack.append([node.right, False])
                
                if node.left:
                    stack.append([node.left, False])
                
        return ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        stack = []
        prev_node, curr_node = None, root
        ans = float('inf')
        
        while stack or curr_node:
            if curr_node:
                stack.append(curr_node)
                curr_node = curr_node.left
            else:
                curr_node = stack.pop()
                if prev_node:
                    ans = min(ans, abs(curr_node.val - prev_node.val))
                prev_node = curr_node
                curr_node = curr_node.right
        
        return ans
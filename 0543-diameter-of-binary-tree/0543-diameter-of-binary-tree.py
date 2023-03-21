# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0
        stack, height = [[root, False]], dict()
        
        while stack:
            node, seen = stack[-1]
            if not seen:
                stack[-1][1] = True
                if node.left:
                    stack.append([node.left, False])
                
                if node.right:
                    stack.append([node.right, False])
                
            else:
                left = height.get(node.left, 0)
                right = height.get(node.right, 0)
                
                if left + right > diameter:
                    diameter = left + right
                height[node] = max(left, right) + 1
                stack.pop()
        return diameter
                
            
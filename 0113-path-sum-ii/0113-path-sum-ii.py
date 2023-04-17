# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []
        
        stack, ans = [(root, [root.val], root.val)], []
        
        while stack:
            node, paths, total = stack.pop()
            
            if not node.left and not node.right and total == targetSum:
                ans.append(paths)
            
            if node.left:
                stack.append((node.left, paths + [node.left.val], total + node.left.val))
            
            if node.right:
                stack.append((node.right, paths + [node.right.val], total + node.right.val))
                
        
        return ans
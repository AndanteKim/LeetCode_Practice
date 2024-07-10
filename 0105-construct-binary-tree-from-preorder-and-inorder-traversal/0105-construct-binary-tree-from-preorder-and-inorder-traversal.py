# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # Iterative
        if not preorder:
            return None
        
        root = TreeNode(preorder[0])
        pre, ino = 1, 0
        stack = []
        stack.append(root)
        
        while pre < len(preorder):
            curr = TreeNode(preorder[pre])
            pre += 1
            prev = None
            
            while stack and stack[-1].val == inorder[ino]:
                prev = stack.pop()
                ino += 1
            
            if prev:
                prev.right = curr
            else:
                stack[-1].left = curr
        
            stack.append(curr)
            
        return root
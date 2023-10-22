# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        ancestors = dict()
        queue = deque([(root, None)])
        
        while queue:
            child, parent = queue.popleft()
            
            if child in ancestors:
                if not ancestors[parent]:
                    return None
                if ancestors[parent].left == parent:
                    ancestors[parent].left = None
                else:
                    ancestors[parent].right = None
                break
            ancestors[child] = parent
            
            if child.left:
                queue.append((child.left, child))
            
            if child.right:
                queue.append((child.right, child))
        
        return root
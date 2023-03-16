# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random

class Solution:
    def __init__(self):
        self.seen: dict[str, int] = {None: None}
    
    def dfs(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not root:
            return None
        
        if self.seen.get(root):
            return self.seen.get(root)
        
        new_root = NodeCopy(root.val)
        self.seen[root] = new_root
        
        new_root.left = self.dfs(root.left)
        new_root.right = self.dfs(root.right)
        new_root.random = self.dfs(root.random)
        return new_root
    
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        new_root = self.dfs(root)
        return new_root
# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random

class Solution:
    def __init__(self):
        self.seen: dict = {None: None}
    
    def bfs(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        if not root:
            return None
        
        pending = deque()
        pending.append(root)
        self.seen[root] = NodeCopy(root.val)
        
        while pending:
            old_node = pending.popleft()
            new_node = self.seen[old_node]
            
            if old_node.left:
                if not old_node.left in self.seen:
                    pending.append(old_node.left)
                    self.seen[old_node.left] = NodeCopy(old_node.left.val)
                new_node.left = self.seen[old_node.left]
            
            if old_node.right:
                if not old_node.right in self.seen:
                    pending.append(old_node.right)
                    self.seen[old_node.right] = NodeCopy(old_node.right.val)
                new_node.right = self.seen[old_node.right]
        
            if old_node.random:
                if not old_node.random in self.seen:
                    pending.append(old_node.random)
                    self.seen[old_node.random] = NodeCopy(old_node.random.val)
                new_node.random = self.seen[old_node.random]
            
        return self.seen[root]
        
    
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        new_root = self.bfs(root)
        return new_root
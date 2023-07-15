# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parents = defaultdict(lambda: None)
        
        queue = deque([(root, None)])
        
        while queue:
            node, parent = queue.popleft()
            parents[node] = parent
            
            if node.left:
                queue.append((node.left, node))
            
            if node.right:
                queue.append((node.right, node))
            
        stack = [p]
        while stack:
            node = stack.pop()    
            if node == q:
                return p
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        
        stack = [q]
        while stack:
            node = stack.pop()
            if node == p:
                return q
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        
        p_copy = parents[p]
        while p_copy:
            q_copy = parents[q]
            while q_copy and p_copy != q_copy:
                q_copy = parents[q_copy]
            if p_copy == q_copy:
                break
            p_copy = parents[p_copy]
            
        return p_copy
            
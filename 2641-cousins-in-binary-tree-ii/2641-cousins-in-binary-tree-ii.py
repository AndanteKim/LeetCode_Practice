# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root.val = 0
        if root.left:
            root.left.val = 0
        if root.right:
            root.right.val = 0
        queue, ancestors, level_sums = deque([(root, 0)]), [], dict()
            
        while queue:
            level_sum, size = 0, len(queue)
            
            for _ in range(size):
                node, depth = queue.popleft()
                ancestors.append(node)
                level_sum += node.val
                
                if node.left:
                    queue.append((node.left, depth + 1))
                    
                if node.right:
                    queue.append((node.right, depth + 1))
            
            level_sums[depth] = level_sum
        
        if root.left:
            queue.append((root.left, 1))
        
        if root.right:
            queue.append((root.right, 1))
        
        while queue:
            node, depth = queue.popleft()
                
            if depth + 1 in level_sums:
                if node.left and node.right:
                    temp = node.left.val + node.right.val
                    node.left.val = level_sums[depth + 1] - temp
                    node.right.val = level_sums[depth + 1] - temp
                elif node.left:
                    node.left.val = level_sums[depth + 1] - node.left.val
                elif node.right:
                    node.right.val = level_sums[depth + 1] - node.right.val
                
            if node.left:
                queue.append((node.left, depth + 1))
                
            if node.right:
                queue.append((node.right, depth + 1))
        
            
        return root
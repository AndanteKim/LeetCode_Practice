# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # Base case
        if not root:
            return root
        
        queue, level_sums = deque([root]), []
            
        # First BFS: Calculate sum of nodes at each level
        while queue:
            level_sum, size = 0, len(queue)
            
            for _ in range(size):
                node = queue.popleft()
                level_sum += node.val
                
                if node.left:
                    queue.append(node.left)
                    
                if node.right:
                    queue.append(node.right)
            
            level_sums.append(level_sum)
        
        # Second BFS: Update each node's value to sum of its cousins
        queue.append(root)
        root.val = 0    # Root has no cousins
        level_index = 1
        while queue:
            level = len(queue)
            for _ in range(level):
                node = queue.popleft()
            
                sibling_sum = (node.left.val if node.left else 0) + (node.right.val if node.right else 0)
                if node.left:
                    node.left.val = level_sums[level_index] - sibling_sum
                    queue.append(node.left)
                    
                if node.right:
                    node.right.val = level_sums[level_index] - sibling_sum
                    queue.append(node.right)
                    
            level_index += 1
            
        return root
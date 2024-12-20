# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None     # Return None if the tree is empty.
        
        queue, level = deque([root]), 0     # Start BFS with the root node
        
        while queue:
            n, curr_lvl_nodes = len(queue), []
            
            # Process all nodes at the current level.
            for _ in range(n):
                node = queue.popleft()
                curr_lvl_nodes.append(node)
                
                if node.left:
                    queue.append(node.left)
                
                if node.right:
                    queue.append(node.right)
                
            # Reverse node values if the current level is odd
            if level % 2:
                left, right = 0, len(curr_lvl_nodes) - 1
                
                while left < right:
                    curr_lvl_nodes[left].val, curr_lvl_nodes[right].val = curr_lvl_nodes[right].val, curr_lvl_nodes[left].val
                    left += 1
                    right -= 1
            
            level += 1
            
        return root     # Return the modified tree root.
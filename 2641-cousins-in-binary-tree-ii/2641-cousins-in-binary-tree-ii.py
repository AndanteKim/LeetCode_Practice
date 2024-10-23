# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        
        queue = deque([root])
        prev_level_sum = root.val
        
        while queue:
            level_size = len(queue)
            curr_level_sum = 0
            
            for _ in range(level_size):
                node = queue.popleft()
                
                # Update node value to cousin sum
                node.val = prev_level_sum - node.val
                
                # Calculate sibling sum
                sibling_sum = (node.left.val if node.left else 0) + (node.right.val if node.right else 0)
                
                if node.left:
                    # Accumulate current level sum
                    curr_level_sum += node.left.val
                    # Update left child's value
                    node.left.val = sibling_sum
                    # Add to queue for the next level
                    queue.append(node.left)
                
                if node.right:
                    # Accumulate current level sum
                    curr_level_sum += node.right.val
                    node.right.val = sibling_sum
                    # Add to queue for next level
                    queue.append(node.right)
            prev_level_sum = curr_level_sum     # Update previous level sum for next iteration
            
        return root
                    
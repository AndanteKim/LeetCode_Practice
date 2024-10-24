# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        # Checks whether the given pair of nodes should be examined -
        # be pushed into the stack
        def check_node_values(node1: TreeNode, node2: TreeNode) -> bool:
            if not (node1 or node2):
                return True
            
            if node1 and node2 and node1.val == node2.val:
                return True
            
            return False
        
        # Initialize stack to store pairs of nodes
        s = [(root1, root2)]
        
        while s:
            node1, node2 = s.pop()
            
            if not (node1 or node2):
                continue
                
            if not (node1 and node2):
                return False
            
            if node1.val != node2.val:
                return False
            
            # Check both configurations: no swap and swap
            if check_node_values(node1.left, node2.left) and check_node_values(node1.right, node2.right):
                s.append((node1.left, node2.left))
                s.append((node1.right, node2.right))
            elif check_node_values(node1.left, node2.right) and check_node_values(node1.right, node2.left):
                s.append((node1.left, node2.right))
                s.append((node1.right, node2.left))
            else:
                return False
            
        return True
            
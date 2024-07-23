# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        # Maps values to TreeNode pointers
        node_map = dict()
        
        # Store values which are children in the descriptions
        children = set()
        
        # Iterate through description to create nodes and set up tree structure
        # Extract parent value, child value, and whether
        # it's a left child (1) or right child (0)
        for parent, child, is_left in descriptions:
            # Create parent and child nodes if not already created
            if parent not in node_map:
                node_map[parent] = TreeNode(parent)
            
            if child not in node_map:
                node_map[child] = TreeNode(child)
                
            # Attach child node to parent's left or right branch
            if is_left:
                node_map[parent].left = node_map[child]
            else:
                node_map[parent].right = node_map[child]
                
            # Mark child as a child in the set
            children.add(child)
            
        # Find and return the root node
        for node in node_map.values():
            if node.val not in children:
                return node # Root node found
            
        return None # Should not occur according to problem statement
             
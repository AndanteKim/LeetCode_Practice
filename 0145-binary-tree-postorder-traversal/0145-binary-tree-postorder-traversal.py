# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        
        # If the root is None, return an empty list
        if not root:
            return ans
        
        # Create a dummy node to simplify edge cases
        dummy_node = TreeNode(-1)
        dummy_node.left = root
        root = dummy_node
        
        # Traverse the tree
        while root:
            # If the current node has a left child
            if root.left:
                predecessor = root.left
                
                # Find the rightmost node in the left subtree or the thread back to the current node
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right
                
                # Create a thread if it doesn't exist
                if not predecessor.right:
                    predecessor.right = root
                    root = root.left
                else:
                    # Process the nodes in the left subtree
                    node = predecessor
                    self._reverse_subtree_links(root.left, predecessor)
                    
                    # Add nodes from right to left
                    while node != root.left:
                        ans.append(node.val)
                        node = node.right
                        
                    # Add root.left's value.
                    ans.append(node.val)
                    self._reverse_subtree_links(predecessor, root.left)
                    predecessor.right = None
                    root = root.right
                    
            else:
                # Move to the right child if there's no left child
                root = root.right
                
        return ans
    
    def _reverse_subtree_links(self, start_node: TreeNode, end_node: TreeNode) -> None:
        # If the start and end nodes are the same, no need to reverse
        if start_node == end_node:
            return
        
        prev = None
        curr = start_node
        next = None
        
        # Reverse the direction of the pointers in the subtree
        while curr != end_node:
            next = curr.right
            curr.right = prev
            prev = curr
            curr = next
            
        # Reverse the last node
        curr.right = prev
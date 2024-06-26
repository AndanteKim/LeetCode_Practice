# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        
        # Step 1: Create the backbone (vine)
        # Temporary dummy node
        vine_head = TreeNode(0)
        vine_head.right = root
        curr = vine_head
        while curr.right:
            if curr.right.left:
                self.right_rotate(curr, curr.right)
            else:
                curr = curr.right
                
        # Step 2: Count the nodes
        node_count = 0
        curr = vine_head.right
        while curr:
            node_count += 1
            curr = curr.right
            
        # Step 3: Create a balanced BST
        m = 2 ** int(log2(node_count + 1)) - 1
        self.make_rotations(vine_head, node_count - m)
        while m > 1:
            m >>= 1
            self.make_rotations(vine_head, m)
            
        balanced_root = vine_head.right
        # Delete the temporary dummy node
        vine_head = None
        return balanced_root
    
    # Function to perform a right rotation    
    def right_rotate(self, parent: TreeNode, node: TreeNode) -> None:
        tmp = node.left
        node.left = tmp.right
        tmp.right = node
        parent.right = tmp
        
    # Function to perform a left rotation
    def left_rotate(self, parent: TreeNode, node: TreeNode) -> None:
        tmp = node.right
        node.right = tmp.left
        tmp.left = node
        parent.right = tmp
        
    # Function to perform a series of left rotations to balance the vine
    def make_rotations(self, vine_head: TreeNode, count: int) -> None:
        curr = vine_head
        for _ in range(count):
            tmp = curr.right
            self.left_rotate(curr, tmp)
            curr = curr.right
    
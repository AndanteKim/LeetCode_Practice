# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def compute_depth(self, node: TreeNode) -> int:
        """
        Return tree depth in O(d) time.
        """
        
        d = 0
        while node.left:
            node = node.left
            d += 1
            
        return d
    
    def exists(self, idx: int, d: int, node: TreeNode) -> bool:
        """
        Last level nodes are enumerated from 0 to 2 ** d - 1 (left -> right)
        Return True if last level node idx exists.
        Binary search with O(d) complexity
        """
        left, right = 0, 2 ** d - 1
        for _ in range(d):
            pivot = left + ((right - left) >> 1)
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
                
        return True if node else False
        
    
    def countNodes(self, root: Optional[TreeNode]) -> int:
        # If the tree node is empty
        if not root:
            return 0
        
        d = self.compute_depth(root)
        # If the tree contains 1 node
        if d == 0:
            return 1
        
        # Last level node are enumerated from to 2 ** d - 1 (left -> right)
        # Perform binary search to check how many nodes exist.
        left, right = 1, 2 ** d - 1
        
        while left <= right:
            pivot = left + ((right - left) >> 1)
            if self.exists(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
                
        # The tree contains 2 ** d - 1 nodes on the first (d - 1) levels
        # and left nodes on the last level.
        return (2 ** d - 1) + left
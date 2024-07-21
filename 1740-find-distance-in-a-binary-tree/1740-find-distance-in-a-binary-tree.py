# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Private helper function
    def __distance(self, root: Optional[TreeNode], p: int, q: int, depth: int) -> int:
        if not root or p == q:
            return 0
        
        # If either p or q is found, calculate the ret_dist as the maximum
        # of depth and ret_dist value for left and right subtrees.
        if root.val == p or root.val == q:
            left = self.__distance(root.left, p, q, 1)
            right = self.__distance(root.right, p, q, 1)
            
            return max(left, right) if left > 0 or right > 0 else depth
        
        # Otherwise, calculate the ret_dist as sum of ret_dist of left
        # and right subtree.
        left = self.__distance(root.left, p, q, depth + 1)
        right = self.__distance(root.right, p, q, depth + 1)
        
        ret_dist = left + right
        
        # If current node is the LCA, subtract twice of depth.
        if left != 0 and right != 0:
            ret_dist -= 2 * depth
        return ret_dist
    
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        return self.__distance(root, p, q, 0)
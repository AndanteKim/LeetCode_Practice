# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _post_order(self, curr: TreeNode, distance: int) -> List[int]:
        if not curr:
            return [0] * 12
        
        elif not (curr.left or curr.right):
            curr = [0] * 12
            # Leaf node's distance from itself is 0
            curr[0] = 1
            return curr
        
        # Leaf node count for a given distance i
        left = self._post_order(curr.left, distance)
        right = self._post_order(curr.right, distance)
        
        curr = [0] * 12
        
        # Combine the counts from the left and right subtree and shift by
        # +1 distance
        for i in range(10):
            curr[i + 1] += left[i] + right[i]
            
        # Initialize to total number of good leaf nodes pairs from left and right subtrees.
        curr[11] = left[11] + right[11]
        
        # Iterate through possible leaf node distance pairs
        for d1 in range(distance + 1):
            for d2 in range(distance + 1):
                if 2 + d1 + d2 <= distance:
                    # If the total path distance is less than the given distance limit,
                    # then add to the total number of good pairs
                    curr[11] += left[d1] * right[d2]
                    
        return curr
    
    
    def countPairs(self, root: TreeNode, distance: int) -> int:
        return self._post_order(root, distance)[11]
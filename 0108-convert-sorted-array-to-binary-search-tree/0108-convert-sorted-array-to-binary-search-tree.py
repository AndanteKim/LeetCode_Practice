# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def helper(left: int, right: int) -> TreeNode:
            # Base case
            if left > right:
                return None
            
            # Always choose right middle node as a root
            mid = (left + right) >> 1
            if (left + right) % 2:
                mid += 1
                
            # Preorder traversal: node -> left -> right
            root = TreeNode(nums[mid])
            root.left = helper(left, mid - 1)
            root.right = helper(mid + 1, right)
            
            return root
        
        return helper(0, len(nums) - 1)
            
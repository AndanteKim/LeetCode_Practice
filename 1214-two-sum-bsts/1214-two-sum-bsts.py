# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def morris_traversal(self, root: Optional[TreeNode]) -> Iterator[int]:
        current = root
        while current:
            if not current.left:
                yield current.val
                current = current.right
            else:
                pre = current.left
                while pre.right and pre.right != current:
                    pre = pre.right
                if not pre.right:
                    pre.right = current
                    current = current.left
                else:
                    pre.right = None
                    yield current.val
                    current = current.right
                    
    def reversed_morris_traversal(self, root: Optional[TreeNode]) -> Iterator[int]:
        current = root
        while current:
            if not current.right:
                yield current.val
                current = current.left
            else:
                pre = current.right
                while pre.left and pre.left != current:
                    pre = pre.left
                if not pre.left:
                    pre.left = current
                    current = current.right
                else:
                    pre.left = None
                    yield current.val
                    current = current.left
    
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        iterator1 = self.morris_traversal(root1)
        iterator2 = self.reversed_morris_traversal(root2)
        val1, val2 = next(iterator1, None), next(iterator2, None)
        
        while val1 != None and val2 != None:
            if val1 + val2 == target:
                return True
            elif val1 + val2 < target:
                val1 = next(iterator1, None)
            else:
                val2 = next(iterator2, None)
        
        return False
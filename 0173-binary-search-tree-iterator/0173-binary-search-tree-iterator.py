# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        # Array containing all the nodes in the sorted order
        self.nodes_sorted = []
        
        # Pointer to the next smallest element in the BST
        self.idx = -1
        
        # Call to flatten the input binary search tree.
        self._inorder(root)

    def _inorder(self, root: TreeNode) -> None:
        if not root:
            return
        self._inorder(root.left)
        self.nodes_sorted.append(root.val)
        self._inorder(root.right)
    
    def next(self) -> int:
        """
        @return the next smallest number
        """
        self.idx += 1
        return self.nodes_sorted[self.idx]
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.idx + 1 < len(self.nodes_sorted)

# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
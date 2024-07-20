# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        # Find the lowest common ancestor of p and q
        lca = self.__find_LCA(root, p, q)
        return self.__depth(lca, p) + self.__depth(lca, q)
    
    # Function to find the LCA of the given nodes
    def __find_LCA(self, root: Optional[TreeNode], p: int, q: int) -> TreeNode:
        if not root or root.val == p or root.val == q:
            return root
        
        left = self.__find_LCA(root.left, p, q)
        right = self.__find_LCA(root.right, p, q)
        
        if left and right:
            return root
        
        return left if left else right
    
    # Function to find the depth of the node with respect to LCA.
    def __depth(self, root: TreeNode, target: int, curr_depth = 0):
        # Node not found
        if not root:
            return -1
        
        if root.val == target:
            return curr_depth
        
        # Check left subtree
        left_depth = self.__depth(root.left, target, curr_depth + 1)
        
        if left_depth != -1:
            return left_depth
        
        # If not in left subtree, it's guaranteed to be in the right subtree
        return self.__depth(root.right, target, curr_depth + 1)
    
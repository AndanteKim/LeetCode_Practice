# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        # Find the Lowest Common Ancestor(LCA) of start and destination nodes
        LCA = self._find_lowest_LCA(root, startValue, destValue)
        
        path_to_start, path_to_dest = [], []
        
        # Find paths from LCA to start and destination nodes
        self._find_path(LCA, startValue, path_to_start)
        self._find_path(LCA, destValue, path_to_dest)
        
        directions = []
        
        # Add "U" for each step to go up from start to LCA
        directions.extend("U" * len(path_to_start))
        
        # Append the path from LCA to destination
        directions.extend(path_to_dest)
        
        return "".join(directions)
    
    def _find_lowest_LCA(self, node: TreeNode, v1: int, v2: int) -> TreeNode:
        if not node:
            return None
        
        if node.val == v1 or node.val == v2:
            return node
        
        left_lca = self._find_lowest_LCA(node.left, v1, v2)
        right_lca = self._find_lowest_LCA(node.right, v1, v2)
        
        if not left_lca:
            return right_lca
        elif not right_lca:
            return left_lca
        else:
            return node # Both values found, this is the LCA
        
    def _find_path(self, node: TreeNode, target: int, path: List[str]) -> bool:
        if not node:
            return False
        
        if node.val == target:
            return True
        
        # Try left subtree
        path.append("L")
        if self._find_path(node.left, target, path):
            return True
        path.pop() # Remove last character
        
        # Try right subtree
        path.append("R")
        if self._find_path(node.right, target, path):
            return True
        path.pop() # Remove last character
        
        return False
        
        
        
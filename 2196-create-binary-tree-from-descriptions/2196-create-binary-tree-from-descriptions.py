# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        root, seen, ancestors = None, dict(), dict()
        
        for p, c, is_left in descriptions:
            if p in seen:
                tree_p, tree_c = seen[p], None
                if c in seen:
                    tree_c = seen[c]
                else:
                    tree_c = TreeNode(c)
                
                if is_left:
                    tree_p.left = tree_c
                else:
                    tree_p.right = tree_c
                ancestors[tree_c] = tree_p
                
            else:
                tree_p, tree_c = TreeNode(p), None
                if c in seen:
                    tree_c = seen[c]
                else:
                    tree_c = TreeNode(c)
                    
                if is_left:
                    tree_p.left = tree_c
                else:
                    tree_p.right = tree_c
                
                ancestors[tree_c] = tree_p
            seen[c], seen[p] = tree_c, tree_p
        
        for tree in seen.values():
            if tree not in ancestors:
                root = tree

        return root
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        # Get the node with the smallest value greater than this one.
        def get_successor(node: TreeNode) -> TreeNode:
            succ = node.right
            while succ.left and succ.left != node:
                succ = succ.left
                
            return succ
        
        total, node = 0, root
        
        while node:
            # If there is no right subtree, then we can visit this node and
            # continue traversing left.
            if not node.right:
                total += node.val
                node.val = total
                node = node.left
            
            # If there is a right subtree, then there is a node that has a greater
            # value than the current one. Therefore, we must traverse that node first.
            else:
                succ = get_successor(node)
                # If there is no left subtree (or right subtree, because we're
                # in this branch of control flow), make a temporary connection
                # back to the current node.
                if not succ.left:
                    succ.left = node
                    node = node.right
                
                # If there is a left subtree, it's a link that we created on
                # a previous pass, so we should unlink it and visit this node.
                else:
                    succ.left = None
                    total += node.val
                    node.val = total
                    node = node.left
                    
        return root
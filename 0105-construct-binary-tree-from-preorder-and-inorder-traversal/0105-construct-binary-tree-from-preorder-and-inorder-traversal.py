# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def array_to_tree(left: int, right: int) -> Optional[TreeNode]:
            nonlocal preorder_index
            # base case: if there is no elements to construct the tree
            if left > right:
                return None
            
            # select the preorder_index element as the root and increment it
            root_val = preorder[preorder_index]
            root = TreeNode(root_val)
            preorder_index += 1
            
            # build left and right subtree
            # excluding inorder_index_maa[root_val] element because it's the root
            root.left = array_to_tree(left, inorder_index_map[root_val] - 1)
            root.right = array_to_tree(inorder_index_map[root_val] + 1, right)
            
            return root
        
        inorder_index_map = dict()
        # Build a hash map to store value -> its index relations
        for idx, val in enumerate(inorder):
            inorder_index_map[val] = idx
        preorder_index = 0
        
        return array_to_tree(0, len(preorder) - 1)
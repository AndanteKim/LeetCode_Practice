# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return []
        
        to_delete_set, forest = set(to_delete), []
        
        queue = deque([root])
        
        while queue:
            curr = queue.popleft()
            
            if curr.left:
                queue.append(curr.left)
                
                # Disconnect the left child if it needs to be deleted
                if curr.left.val in to_delete_set:
                    curr.left = None
                   
            if curr.right:
                queue.append(curr.right)
                
                # Disconnect the right child if it needs to be deleted
                if curr.right.val in to_delete_set:
                    curr.right = None
                    
            # If the current node needs to be deleted, add its non-null children to the forest
            if curr.val in to_delete_set:
                if curr.left:
                    forest.append(curr.left)
                
                if curr.right:
                    forest.append(curr.right)
        
        # Ensure the root is added to the forest if it's not to be deleted.
        if root.val not in to_delete_set:
            forest.append(root)
            
        return forest
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        # base case
        if depth == 1:
            new_node = TreeNode(val)
            new_node.left = root
            return new_node
        
        queue = deque([(None, root, 1)])
        
        while queue:
            parent, curr, curr_depth = queue.popleft()
            
            if parent and curr_depth == depth:
                new_node = TreeNode(val)
                if parent.left == curr:
                    parent.left, new_node.left = new_node, curr
                else:
                    parent.right, new_node.right = new_node, curr
                continue
            
            if not curr:
                continue
            
            queue.append((curr, curr.left, curr_depth + 1))
            queue.append((curr, curr.right, curr_depth + 1))
            
        return root
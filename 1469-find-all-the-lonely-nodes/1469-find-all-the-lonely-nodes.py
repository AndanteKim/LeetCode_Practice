# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        ans, queue = [], deque([(root, False)])
        
        while queue:
            curr_node, is_lonely = queue.popleft()
            
            if is_lonely:
                ans.append(curr_node.val)
                
            if curr_node.left:
                queue.append((curr_node.left, curr_node.right == None))
                
            if curr_node.right:
                queue.append((curr_node.right, curr_node.left == None))
                
        return ans
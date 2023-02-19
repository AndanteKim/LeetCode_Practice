# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return root
        
        ans = []
        level_list = deque()
        node_queue = deque([root, None])
        is_order_left = True
        
        while len(node_queue) > 0:
            curr_node = node_queue.popleft()
            
            if curr_node:
                if is_order_left:
                    level_list.append(curr_node.val)
                else:
                    level_list.appendleft(curr_node.val)
                
                if curr_node.left:
                    node_queue.append(curr_node.left)
                
                if curr_node.right:
                    node_queue.append(curr_node.right)
            else:
                ans.append(level_list)
                
                if len(node_queue) > 0:
                    node_queue.append(None)
                
                level_list = deque()
                is_order_left = not is_order_left
        return ans
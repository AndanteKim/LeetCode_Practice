# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return root
        
        queue, ans = deque([(root, 0)]), []
        curr, curr_lv = [], 0
        while queue:
            q, lv = queue.popleft()
            if curr_lv != lv:
                if curr_lv % 2 == 1:
                    ans.append(curr[::-1])
                else:
                    ans.append(curr)
                curr_lv = lv
                curr = []
            
            curr.append(q.val)
            
            if q.left:
                queue.append((q.left, lv + 1))
            
            if q.right:
                queue.append((q.right, lv + 1))
        if curr and curr_lv % 2 == 0:
            ans.append(curr)
        elif curr and curr_lv % 2 == 1:
            ans.append(curr[::-1])
        
        return ans
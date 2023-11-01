# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        max_streak, curr_streak, curr_num = 0, 0, 0
        ans = []
        
        curr = root
        while curr:
            if curr.left:
                # Find the friend
                friend = curr.left
                while friend.right:
                    friend = friend.right
                
                friend.right = curr
                
                # Delete the edge after using it
                left = curr.left
                curr.left = None
                curr = left
            else:
                # Handle the current node
                num = curr.val
                if num == curr_num:
                    curr_streak += 1
                else:
                    curr_streak = 1
                    curr_num = num
                
                if curr_streak > max_streak:
                    ans = []
                    max_streak = curr_streak
                
                if curr_streak == max_streak:
                    ans.append(num)
                
                curr = curr.right
        
        return ans
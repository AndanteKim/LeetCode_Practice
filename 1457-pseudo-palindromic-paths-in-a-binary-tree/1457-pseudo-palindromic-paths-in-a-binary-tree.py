# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        queue, ans = deque([(root, 0)]), 0
        cases = []
        
        while queue:
            node, curr = queue.popleft()
            curr ^= (1 << node.val)
            
            if not node.left and not node.right:
                cases.append(curr)
                
            if node.left:
                queue.append((node.left, curr))
                
            if node.right:
                queue.append((node.right, curr))
        
        for case in cases:
            flag, exist_odd = False, False
            for i in range(1, 10):
                if case & (1 << i):
                    if exist_odd:
                        flag = True
                        break
                    exist_odd = True
                    
            if not flag:
                ans += 1
                
        return ans
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        queue, ans = deque([root]), []

        while queue:
            size, largest_val = len(queue), float('-inf')
            for _ in range(size):
                node = queue.popleft()

                largest_val = max(largest_val, node.val)

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)
            ans.append(largest_val)
        
        return ans



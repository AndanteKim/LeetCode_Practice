# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # Base case
        if not root:
            return []
        
        seen, ans = defaultdict(list), []
        q = deque([(root, 0)])

        while q:
            node, axis = q.popleft()

            seen[axis].append(node.val)

            if node.left:
                q.append((node.left, axis - 1))
            
            if node.right:
                q.append((node.right, axis + 1))

        for axis in sorted(seen.keys()):
            ans.append(seen[axis])
        
        return ans
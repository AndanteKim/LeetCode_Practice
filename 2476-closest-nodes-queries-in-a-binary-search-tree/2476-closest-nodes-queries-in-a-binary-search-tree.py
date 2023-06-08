# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        ans = []
        
        stack, arr, tree = [], [], root
        while stack or tree:
            
            if tree:
                stack.append(tree)
                tree = tree.left
            else:
                tree = stack.pop() 
                arr.append(tree.val)
                tree = tree.right            
        
        n = len(arr)
        for query in queries:
            pos = bisect_left(arr, query)
            
            if pos == n:
                ans.append([arr[pos - 1], -1])
            elif arr[pos] == query:
                ans.append([query, query])
            elif pos == 0:
                ans.append([-1, arr[pos]])
            else:
                ans.append([arr[pos - 1], arr[pos]])
        
        return ans
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
        
        for query in queries:
            curr_pair = [float('-inf'), float('inf')] 
            
            pos = bisect_left(arr, query)
            
            if 0 < pos < len(arr):
                if arr[pos] == query:
                    curr_pair[0], curr_pair[1] = query, query
                else:
                    curr_pair[0] = arr[pos - 1]
                    curr_pair[1] = arr[pos]
                
            else:
                if pos == 0 or pos == len(arr) - 1:
                    if arr[pos] == query:
                        curr_pair[0], curr_pair[1] = query, query
                    else:
                        curr_pair[0], curr_pair[1] = -1, arr[pos]
                else:
                    curr_pair[0], curr_pair[1] = arr[pos - 1], -1
            
            ans.append(curr_pair)
        
        return ans
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        queue, largest_sums = deque([root]), []
        
        while queue:
            size, curr_sum = len(queue), 0
            
            for _ in range(size):
                node = queue.popleft()
                curr_sum += node.val
                
                if node.left:
                    queue.append(node.left)
                    
                if node.right:
                    queue.append(node.right)
                     
            if len(largest_sums) >= k:
                if curr_sum > largest_sums[0]:
                    heappop(largest_sums)
                    heappush(largest_sums, curr_sum)
            else:
                heappush(largest_sums, curr_sum)
                
        return -1 if len(largest_sums) != k else largest_sums[0] 
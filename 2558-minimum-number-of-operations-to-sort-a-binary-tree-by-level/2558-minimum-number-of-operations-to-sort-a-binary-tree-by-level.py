# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        # Calculate minimum swaps needed to sort an array
        def _get_min_swaps(arr: List[int]) -> int:
            swaps = 0
            target = sorted(arr)

            # Map to track current positions of values
            pos = {val: idx for idx, val in enumerate(arr)}

            # For each position, swap until correct value is placed
            for i in range(len(arr)):
                if arr[i] != target[i]:
                    swaps += 1

                    # Update position of swapped values
                    curr_pos = pos[target[i]]
                    pos[arr[i]] = curr_pos
                    arr[curr_pos] = arr[i]
            
            return swaps


        queue, ans = deque([root]), 0

        # Process tree level by using BFS
        while queue:
            size, arr = len(queue), []

            # Store level valus and add children to queue
            for _ in range(size):
                node = queue.popleft()
                arr.append(node.val)

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)
            
            # Add minimum swaps needed for current level
            ans += _get_min_swaps(arr)
        return ans
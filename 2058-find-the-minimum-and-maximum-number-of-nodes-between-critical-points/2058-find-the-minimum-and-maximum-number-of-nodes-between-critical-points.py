# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        ans = [-1, -1]
        
        # Initialize minimum distance to the maximum possible value
        min_dist = float("inf")
        
        # Pointers to track the previous node, current node, and indices
        prev_node, curr_node = head, head.next
        curr_idx, prev_critical_idx = 1, 0
        first_critical_idx = 0
        
        while curr_node.next:
            # Check if the current node is a local maxima or minima
            if (curr_node.val < prev_node.val and curr_node.val < curr_node.next.val)\
            or (curr_node.val > prev_node.val and curr_node.val > curr_node.next.val):
                # If this is the first critical point found
                if prev_critical_idx == 0:
                    prev_critical_idx = curr_idx
                    first_critical_idx = curr_idx
                else:
                    # Calculate the minimum distaance between critical points
                    min_dist = min(min_dist, curr_idx - prev_critical_idx)
                    prev_critical_idx = curr_idx
                    
            # Move to the next node and update indices
            curr_idx += 1
            prev_node = curr_node
            curr_node = curr_node.next
            
        # If at least two critical points were found
        if min_dist != float("inf"):
            max_dist = prev_critical_idx - first_critical_idx
            ans = [min_dist, max_dist]
            
        return ans
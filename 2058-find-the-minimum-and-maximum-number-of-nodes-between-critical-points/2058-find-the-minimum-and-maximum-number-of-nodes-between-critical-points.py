# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        if not head:
            return [-1, -1]
        
        min_idx, max_idx = [], []
        local_min, local_max = float('inf'), float('-inf')
        curr, prev, i = head.next, head, 2
        
        while curr.next:
            # If it's local minima
            if curr.val < prev.val <= curr.next.val or curr.val < curr.next.val <= prev.val:
                min_idx.append(i)
            # If it's local maxima
            elif curr.val > prev.val >= curr.next.val or curr.val > curr.next.val >= prev.val:
                max_idx.append(i)
            curr = curr.next
            prev = prev.next
            i += 1
        
        merged, i, j = [], 0, 0
        while i < len(min_idx) and j < len(max_idx):
            if min_idx[i] <= max_idx[j]:
                merged.append(min_idx[i])
                i += 1
            else:
                merged.append(max_idx[j])
                j += 1
        
        if i < len(min_idx):
            merged.extend(min_idx[i:])
        if j < len(max_idx):
            merged.extend(max_idx[j:])
            
        if len(merged) < 2:
            return [-1, -1]
        ans = [float('inf'), merged[-1] - merged[0]]
        for k in range(len(merged) - 1):
            ans[0] = min(ans[0], merged[k + 1] - merged[k])
        
        return ans
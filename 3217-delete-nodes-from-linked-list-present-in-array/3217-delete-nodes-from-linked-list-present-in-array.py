# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        # Set hashset and dummy nodes
        nums = set(nums)
        dummy = curr = ListNode()
        curr.next = head
        
        while curr:
            # Delete nodes if the next val is in nums
            while curr.next and curr.next.val in nums:
                curr.next = curr.next.next
            
            curr = curr.next
            
        
        return dummy.next
        
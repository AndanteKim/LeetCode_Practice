# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # If the head or the entire list is none, return the head
        if not head or not head.next:
            return head
        
        # Get the middle node
        mid = self.get_mid(head)
        
        # Split the list to left and right and sort them
        left = self.sortList(head)
        right = self.sortList(mid)
        
        # Merge the sorted lists
        return self.merge(left, right)
    
    def merge(self, list1: ListNode, list2: ListNode) -> ListNode:
        dummy = ListNode()
        tail = dummy
        
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 if list1 else list2
        return dummy.next
    
    def get_mid(self, head: ListNode) -> ListNode:
        mid_prev = None
        
        while head and head.next:
            mid_prev = head if not mid_prev else mid_prev.next
            head = head.next.next
            
        mid = mid_prev.next
        mid_prev.next = None
        
        return mid 
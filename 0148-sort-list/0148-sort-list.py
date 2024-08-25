# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def get_count(self, head: ListNode) -> int:
        cnt, ptr = 0, head
        while ptr:
            ptr = ptr.next
            cnt += 1
            
        return cnt
    
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not (head and head.next):
            return head
        
        n = self.get_count(head)
        start = head
        dummy, size = ListNode(), 1
        
        while size < n:
            self.tail = dummy
            while start:
                if not start.next:
                    self.tail.next = start
                    break
                mid = self.split(start, size)
                self.merge(start, mid)
                start = self.next_sublist
            start = dummy.next
            size *= 2
        return dummy.next
    
    def split(self, start: ListNode, size: int) -> ListNode:
        mid_prev = start
        end = start.next
        
        # Use fast and slow approach to find middle and end of the second linked list
        for idx in range(1, size):
            if end and end.next:
                end = end.next.next
            else:
                if end:
                    end = end.next
                    
            if mid_prev.next:
                mid_prev = mid_prev.next
        mid = mid_prev.next
        mid_prev.next = None
        self.next_sublist = end.next if end else None
        if end:
            end.next = None
        # Return the start of the second linked list
        return mid
    
    def merge(self, list1: ListNode, list2: ListNode) -> None:
        dummy = ListNode()
        new_tail = dummy
        
        while list1 and list2:
            if list1.val < list2.val:
                new_tail.next = list1
                list1 = list1.next
                
            else:
                new_tail.next = list2
                list2 = list2.next
            new_tail = new_tail.next
            
        new_tail.next = list1 if list1 else list2
        
        # Traverse till the end of merged list to get the new_tail
        while new_tail.next:
            new_tail = new_tail.next
            
        # Link the old tail with the head of merged list
        self.tail.next = dummy.next
        
        # Update the old tail to the new tail of merged list
        self.tail = new_tail
        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        front, mid, stack, i = head, head, [], 0
        
        if not (front and front.next):
            return

        while front and front.next:
            i += 1
            mid = mid.next
            front = front.next.next
        
        while mid:
            i += 1
            stack.append(mid)
            mid = mid.next
        
        front = head
        while stack:
            temp, rear = front.next, stack.pop()
            front.next = rear
            rear.next = temp
            front = temp
        
        if i % 2:
            front.next.next = None
        else:
            front.next = None
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        curr, n = head, 0
        
        while curr:
            n += 1
            curr = curr.next
        
        width, remainder = divmod(n, k)
        
        ans, curr = [], head
        for i in range(k):
            head = write = ListNode(None)
            for j in range(width + (i < remainder)):
                write.next = write = ListNode(curr.val)
                if curr:
                    curr = curr.next
            ans.append(head.next)
        return ans
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root, flatten = head, []
        dummy = curr = ListNode()
        
        while root:
            flatten.append(root.val)
            root = root.next
            
        flatten.sort()
        for n in flatten:
            curr.next = ListNode(n)
            curr = curr.next
        
        return dummy.next
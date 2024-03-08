# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root, freqs, k, keys = head, dict(), 0, []
        
        while root:
            if freqs.get(root.val, 0) == 0:
                keys.append(root.val)
                k += 1
                freqs[root.val] = freqs.get(root.val, 0) + 1
            else:
                freqs[root.val] += 1
            root = root.next
        
        sentinel = root = ListNode()

        while k > 0:
            root.next = ListNode(freqs.pop(keys.pop()))
            k -= 1
            root = root.next
        
        return sentinel.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        n, curr = 0, head
        st = []
        while curr:
            n += 1
            st.append(curr)
            curr = curr.next

        ans, curr = 0, head
        for i in range(n >> 1):
            ans = max(ans, curr.val + st.pop().val)
            curr = curr.next

        return ans
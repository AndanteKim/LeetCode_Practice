# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        max_value = 100000 # Maximum element value 
        frequencies = [0] * max_value
        current = head

        # Find the frequency of each element
        while current is not None:
            frequencies[current.val - 1] += 1
            current = current.next

        freq_head = ListNode(0)
        current = freq_head

        # Create a linked list of the frequencies of the elements
        for i in range(0, max_value):
            if frequencies[i] > 0:
                current.next = ListNode(frequencies[i])
                current = current.next

        return freq_head.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        freqs, curr = dict(), head
        freq_head = None
        
        # Process the linked list, strong
        # frequency ListNodes in the hash table
        
        while curr:
            # Existing element, increment frequency
            if curr.val in freqs:
                freq_node = freqs[curr.val]
                freq_node.val += 1
                freqs[curr.val] = freq_node
                
            # New element, create hash table entry with frequency node
            else:
                new_freq_node = ListNode(1, freq_head)
                freqs[curr.val] = new_freq_node
                freq_head = new_freq_node
            curr = curr.next
            
        return freq_head
                
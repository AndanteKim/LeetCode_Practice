# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        curr, freq = head, dict()
        
        while curr:
            freq[curr.val]= freq.get(curr.val, 0) + 1
            curr = curr.next
            
        return self.delete_duplicates(head, freq)
    
    # Recursively delete duplicates based on the frequency map.
    def delete_duplicates(self, head: ListNode, freq: Dict[int, int]) -> ListNode:
        if not head:
            return None
        
        # Recursive call for the next node
        updated_next_node = self.delete_duplicates(head.next, freq)
        head.next = updated_next_node
        
        # If the current node is a duplicate, return the updated next node
        if freq[head.val] > 1:
            return updated_next_node
        
        # Otherwise, return the current node
        return head
        
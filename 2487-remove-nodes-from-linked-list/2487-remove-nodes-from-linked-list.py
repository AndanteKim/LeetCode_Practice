# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack, curr = [], head
        
        # Add nodes to the stack
        while curr:
            stack.append(curr)
            curr = curr.next
       
        curr = stack.pop()
        maximum = curr.val
        ans = ListNode(maximum)
        
        # Remove nodes from the stack and add to ans
        while stack:
            curr = stack.pop()
            # curr should not be added to the result
            if curr.val < maximum:
                continue
                
            # Add new node with curr's value to front of the result
            else:
                new_node = ListNode(curr.val)
                new_node.next = ans
                ans = new_node
                maximum = curr.val
        
        return ans
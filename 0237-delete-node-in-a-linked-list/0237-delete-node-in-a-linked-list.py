# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # Overwrite data of next node on current node.
        node.val = node.next.val
        
        # Make current node point to next of next node
        node.next = node.next.next
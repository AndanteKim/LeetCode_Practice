# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        p1, p2 = poly1, poly2
        
        # Initial dummy node
        sum = PolyNode()
        
        # Maintain pointer to last node
        curr = sum
        
        # Maintain two pointers
        while p1 and p2:
            if p1.power == p2.power:
                if p1.coefficient + p2.coefficient != 0:
                    curr.next = PolyNode(p1.coefficient + p2.coefficient, p1.power)
                    curr = curr.next
                p1, p2 = p1.next, p2.next
            elif p1.power > p2.power:
                curr.next = p1
                p1 = p1.next
                curr = curr.next
            else:
                curr.next = p2
                p2 = p2.next
                curr = curr.next
                
        if p1:
            curr.next = p1
        else:
            curr.next = p2
            
        return sum.next
        
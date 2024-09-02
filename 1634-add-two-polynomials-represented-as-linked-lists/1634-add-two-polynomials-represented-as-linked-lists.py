# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        p1, p2 = poly1, poly2
        dummy = prev = curr = PolyNode()
        curr = curr.next
        
        while p1 or p2:
            curr = PolyNode()
            
            if p1 and p2:
                if p1.power == p2.power:
                    if p1.coefficient + p2.coefficient == 0:
                        p1, p2 = p1.next, p2.next
                        continue
                    curr.coefficient = p1.coefficient + p2.coefficient
                    curr.power = p1.power
                    p1, p2 = p1.next, p2.next
                    
                elif p1.power > p2.power:
                    curr.coefficient = p1.coefficient
                    curr.power = p1.power
                    p1 = p1.next
                else:
                    curr.coefficient = p2.coefficient 
                    curr.power = p2.power
                    p2 = p2.next
            elif p1:
                curr.coefficient = p1.coefficient
                curr.power = p1.power
                p1 = p1.next
            else:
                curr.coefficient = p2.coefficient
                curr.power = p2.power
                p2 = p2.next
            
            prev.next = curr
            prev = prev.next
            curr = curr.next
        
        return dummy.next
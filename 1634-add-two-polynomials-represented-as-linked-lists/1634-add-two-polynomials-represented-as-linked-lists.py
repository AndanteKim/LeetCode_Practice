# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        sum_ = PolyNode()
        curr, table = sum_, dict()
        
        # Calculate terms for sum
        self._process_nodes(table, poly1)
        self._process_nodes(table, poly2)
        
        # Iterate over sorted keys and build sum
        for k in sorted(table.keys(), reverse = True):
            curr.next = PolyNode(table[k], k)
            curr = curr.next
            
        return sum_.next
    
    def _process_nodes(self, table: Dict[int, int], node: 'PolyNode') -> None:
        while node:
            if node.power in table:
                new_coeff = node.coefficient + table[node.power]
                if new_coeff == 0:
                    table.pop(node.power)
                else:
                    table[node.power] = new_coeff
            else:
                table[node.power] = node.coefficient
            node = node.next
        
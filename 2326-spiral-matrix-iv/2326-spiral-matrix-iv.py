# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        root = head
        ans = [[-1] * n for _ in range(m)]
        left, right, up, down = 0, n, 0, m
        no_head = False
        
        # Traverse spiral matrix
        while (left < right or up < down) and not no_head:
            # from left to right
            for col in range(left, right):
                if not root:
                    no_head = True
                    break
                
                ans[up][col] = root.val
                root = root.next
            up += 1
            if no_head:
                break
                
            # from up to down
            for row in range(up, down):
                if not root:
                    no_head = True
                    break
                
                ans[row][right - 1] = root.val
                root = root.next
            
            right -= 1
            if no_head:
                break
                
            for col in range(right - 1, left - 1, -1):
                if not root:
                    no_head = True
                    break
                ans[down - 1][col] = root.val
                root = root.next
            down -= 1
            
            if no_head:
                break
                
            for row in range(down - 1, up - 1, -1):
                if not root:
                    no_head = True
                    break
                ans[row][left] = root.val
                root = root.next
            left += 1
        
        return ans
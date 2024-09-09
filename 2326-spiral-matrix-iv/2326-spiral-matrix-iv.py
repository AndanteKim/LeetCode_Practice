# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        # Store the east, south, west, north movements in a matrix.
        i, j, curr_d = 0, 0, 0
        
        movement = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        ans = [[-1] * n for _ in range(m)]
        
        while head:
            ans[i][j] = head.val
            new_i, new_j = i + movement[curr_d][0], j + movement[curr_d][1]
            
            # If we bump into an edge or an already filled cell, change the direction.
            if min(new_i, new_j) < 0 or new_i >= m or new_j >= n or ans[new_i][new_j] != -1:
                curr_d = (curr_d + 1) % 4
            
            i += movement[curr_d][0]
            j += movement[curr_d][1]
            
            head = head.next
            
        return ans
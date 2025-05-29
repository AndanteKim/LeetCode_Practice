# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, head: Optional[ListNode], m: int, n: int) -> Optional[ListNode]:
        curr_node, last_node = head, head

        while curr_node:
            # Initialize m count to m and n count to n
            m_cnt, n_cnt = m, n
            lastm_node = None

            # traverse m nodes
            while curr_node and m_cnt > 0:
                lastm_node = curr_node
                curr_node = curr_node.next
                m_cnt -= 1

            # traverse n nodes
            while curr_node and n_cnt > 0:
                curr_node = curr_node.next
                n_cnt -= 1

            # delete n nodes
            lastm_node.next = curr_node

        return head

             
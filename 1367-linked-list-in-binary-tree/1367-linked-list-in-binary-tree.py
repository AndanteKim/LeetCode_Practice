# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        # Build the pattern and prefix table from the linked list
        pattern, prefix_table = [head.val], [0]
        pattern_idx = 0
        head = head.next
        
        while head:
            while pattern_idx > 0 and head.val != pattern[pattern_idx]:
                pattern_idx = prefix_table[pattern_idx - 1]
                
            pattern_idx += 1 if head.val == pattern[pattern_idx] else 0
            pattern.append(head.val)
            prefix_table.append(pattern_idx)
            head = head.next
            
        # Perform DFS to search for the pattern in the tree
        return self._search_in_tree(root, 0, pattern, prefix_table)
    
    def _search_in_tree(self, node: TreeNode, pattern_idx, pattern: List[int], prefix_table: List[int]) -> bool:
        if not node:
            return False
        
        while pattern_idx > 0 and node.val != pattern[pattern_idx]:
            pattern_idx = prefix_table[pattern_idx - 1]
        pattern_idx += 1 if node.val == pattern[pattern_idx] else 0
        
        # Check if the pattern is fully matched
        if pattern_idx == len(pattern):
            return True
        
        # Recursively search left and right subtrees
        return self._search_in_tree(node.left, pattern_idx, pattern, prefix_table) or \
    self._search_in_tree(node.right, pattern_idx, pattern, prefix_table)
        
        
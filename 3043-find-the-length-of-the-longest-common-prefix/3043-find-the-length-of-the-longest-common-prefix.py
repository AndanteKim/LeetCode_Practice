class TrieNode:
    def __init__(self):
        # Each node has up to 10 possible children
        self.children = [None] * 10
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    # Insert a number into the Trie by treating it as a string of digits
    def insert(self, num: int) -> None:
        node = self.root
        
        for d in str(num):
            idx = int(d)
            if not node.children[idx]:
                node.children[idx] = TrieNode()
            node = node.children[idx]
            
    # Find the longest common prefix for a number in arr2 with the Trie
    def find_longest_prefix(self, num: int) -> int:
        length, node = 0, self.root
        
        for d in str(num):
            idx = int(d)
            if node.children[idx]:
                # Increase length if the current digit matches
                length += 1
                node = node.children[idx]
            else:
                # Stop if no match for the current digit
                break
                
        return length

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        trie = Trie()
        
        # Step 1: Insert all numbers from arr1 into the Trie
        for num in arr1:
            trie.insert(num)
        
        longest_prefix = 0
        
        # Step2: Find the longest prefix match for each number in arr2
        for num in arr2:
            length = trie.find_longest_prefix(num)
            longest_prefix = max(longest_prefix, length)
            
        return longest_prefix
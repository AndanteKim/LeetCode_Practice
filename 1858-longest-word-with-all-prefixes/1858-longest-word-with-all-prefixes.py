class TrieNode:
    def __init__(self):
        self.is_end = False
        self.children = dict()


class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    # Insert a word into the trie
    def _insert(self, s: str) -> None:
        curr = self.root
        for c in s:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.is_end = True
    
    # Check if all prefixes of the word exists in the trie
    def _has_all_prefixes(self, s: str) -> bool:
        curr = self.root
        for c in s:
            if c not in curr.children or not curr.children[c].is_end:
                return False
            curr = curr.children[c]
        return True

class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie, longest_valid_word = Trie(), ""
        
        # Insert all words into the trie
        for word in words:
            trie._insert(word)
            
        # Check each word and update the longest valid word
        for word in words:
            if trie._has_all_prefixes(word):
                if len(word) > len(longest_valid_word) or \
                (len(word) == len(longest_valid_word) and word < longest_valid_word):
                    longest_valid_word = word
        return longest_valid_word
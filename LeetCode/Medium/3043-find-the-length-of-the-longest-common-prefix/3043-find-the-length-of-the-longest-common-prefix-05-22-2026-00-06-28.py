class TrieNode:
    def __init__(self):
        self.is_end = False
        self.children = dict()


class Solution:
    def insert(self, node: 'TrieNode', num: str) -> None:
        for c in num:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_end = True

    def search(self, node: 'TrieNode', num: str) -> int:
        prefix = 0
        for c in num:
            if c not in node.children:
                return prefix
            prefix += 1
            node = node.children[c]

        return prefix


    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        ans = 0
        root = TrieNode()

        for num in arr1:
            node = root
            self.insert(node, str(num))

        for num in arr2:
            node = root
            ans = max(ans, self.search(node, str(num)))

        return ans
class TrieNode:
    def __init__(self):
        self.words = []
        self.children = dict()

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        # build Trie
        root = TrieNode()
        for product in products:
            curr = root
            for c in product:
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                curr = curr.children[c]
                curr.words.append(product)
                curr.words.sort()
                
                if len(curr.words) > 3:
                    curr.words.pop()
                
        # search word
        curr, ans = root, [] 
        for c in searchWord:
            words = []
            if c in curr.children:
                curr = curr.children[c]
                ans.append(curr.words)
            else:
                curr.children = {}
                ans.append([])
        
        return ans
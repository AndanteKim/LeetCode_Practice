class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        n = len(words)
        cnt = Counter(words)
        bucket = [{} for _ in range(n + 1)]
        self.k = k
        
        def add_word(trie: Mapping, word: str) -> None:
            root = trie
            for c in word:
                if c not in root:
                    root[c] = {}
                root = root[c]
            root['#'] = {}
        
        def get_words(trie: Mapping, prefix: str) -> List[str]:
            if self.k == 0:
                return []
            res = []
            if '#' in trie:
                self.k -= 1
                res.append(prefix)
            
            for i in range(26):
                c = chr(ord('a') + i)
                if c in trie:
                    res += get_words(trie[c], prefix + c)
            return res
        
        for word, freq in cnt.items():
            add_word(bucket[freq], word)
        
        ans = []
        for i in range(n, 0, -1):
            if self.k == 0:
                return ans
            if bucket[i]:
                ans += get_words(bucket[i], '')
        return ans
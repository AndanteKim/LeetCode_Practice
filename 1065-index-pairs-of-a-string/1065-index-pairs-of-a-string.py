class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        ans, n = [], len(text)
        
        for word in words:
            size = len(word)
            for i in range(n - size + 1):
                if word == text[i : i + size]:
                    ans.append([i, i + size - 1])
        ans.sort(key = lambda x: (x[0], x[1]))
        
        return ans
            
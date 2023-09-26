class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        c, pos = Counter(s), 0
        
        # find pos - the index of the leftmost letter in our solution
        # we create a counter and end the iteration once the suffix doesn't have each unique character
        # pos will be the index of the smallest character we encounter before the iteration ends
        
        for i in range(len(s)):
            if s[i] < s[pos]:
                pos = i
            c[s[i]] -= 1
            if c[s[i]] == 0:
                break
        
        return s[pos] + self.removeDuplicateLetters(s[pos:].replace(s[pos], "")) if s else ''
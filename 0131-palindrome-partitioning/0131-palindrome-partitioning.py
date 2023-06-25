class Solution:
    def is_palindrome(self, word: str, start: int, end: int) -> bool:
        i, j = start, end
        while i < j:
            if word[i] != word[j]:
                return False
            i += 1
            j -= 1
        return True
    
    def backtrack(self, start: int, curr: List[str], s: str, ans: List[List[str]]) -> None:
        if start >= len(s):
            ans.append(curr[:])
        
        for end in range(start, len(s)):
            if self.is_palindrome(s, start, end):
                curr.append(s[start: end + 1])
                self.backtrack(end + 1, curr, s, ans)
                curr.pop()
    
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        self.backtrack(0, [], s, ans)
        
        return ans
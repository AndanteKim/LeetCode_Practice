class Solution:
    def isPalindrome(self, s: str, low: int, high: int) -> bool:
        while low < high:
            if s[low] != s[high]:
                return False
            low += 1
            high -= 1
        return True
    
    def dfs(self, ans: List[List[str]], s: str, start: int, currentList: List[str]) -> None:
        if start >= len(s): ans.append(currentList.copy())
        for end in range(start, len(s)):
            if self.isPalindrome(s, start, end):
                currentList.append(s[start: end + 1])
                self.dfs(ans, s, end + 1, currentList)
                currentList.pop()
    
    def partition(self, s: str) -> List[List[str]]:
        ans, currentList = [], []
        self.dfs(ans, s, 0, currentList)
        return ans
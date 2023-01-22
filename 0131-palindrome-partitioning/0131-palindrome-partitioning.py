class Solution:
    def dfs(self, ans: List[List[str]], s: str, start: int, currentList: List[str], dp: List[List[bool]]) -> None:
        if start >= len(s): ans.append(currentList.copy())
        
        for end in range(start, len(s)):
            if s[start] == s[end] and (end - start <= 2 or dp[start + 1][end - 1]):
                dp[start][end] = True
                currentList.append(s[start : end + 1])
                self.dfs(ans, s, end + 1, currentList, dp)
                currentList.pop()
    
    
    def partition(self, s: str) -> List[List[str]]:
        length = len(s)
        dp = [[False] * length for _ in range(length)]
        answer, currentList = [], []
        self.dfs(answer, s, 0, currentList, dp)
        return answer
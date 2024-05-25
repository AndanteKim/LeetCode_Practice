class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def backtrack(i: int, curr: List[str]) -> None:
            if i >= n:
                if i == n:
                    ans.append(" ".join(curr))
                return
            
            for j in range(i + 1, n + 1):
                substr = s[i:j]

                if substr in word_dict:
                    curr.append(substr)
                    backtrack(j, curr)
                    curr.pop()
        
        n, word_dict = len(s), {word for word in wordDict}
        ans = []
        backtrack(0, [])
        
        return ans
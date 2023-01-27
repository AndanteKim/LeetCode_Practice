class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        
        dictionary = {word for word in words}
        ans = []
        for word in words:
            n = len(word)
            dp = [False] * (n + 1)
            dp[0] = True
            for i in range(1, n+1):
                start = 1 if i == n else 0
                for j in range(start, i):
                    if dp[i]:
                        continue
                    dp[i] = dp[j] and word[j:i] in dictionary
                    
            if dp[n]:
                ans.append(word)
        return ans
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        dp = dict()
        words.sort(key = len)
        ans = 1
        
        for word in words:
            curr_length = 1
            
            # find all possible predecessors for the current word by removing one letter at a time
            for i in range(len(word)):
                predecessor = word[:i] + word[i + 1 : len(word) + 1]
                
                if predecessor in dp:
                    prev_length = dp[predecessor]
                    curr_length = max(curr_length, prev_length + 1)
            dp[word] = curr_length
            ans = max(ans, curr_length)
        
        return ans
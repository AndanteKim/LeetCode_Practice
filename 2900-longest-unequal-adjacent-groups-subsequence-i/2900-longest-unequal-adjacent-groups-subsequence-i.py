class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        ans, n = [], len(words)
        curr = -1

        for i in range(n):
            if curr == -1 or curr != groups[i]:
                curr = groups[i]
                ans.append(words[i])

        return ans
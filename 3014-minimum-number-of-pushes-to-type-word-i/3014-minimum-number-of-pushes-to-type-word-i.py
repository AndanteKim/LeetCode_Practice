class Solution:
    def minimumPushes(self, word: str) -> int:
        push = 0
        ans, n = 0, len(word)

        for c in word:
            ans += (push // 8) + 1
            push += 1

        return ans

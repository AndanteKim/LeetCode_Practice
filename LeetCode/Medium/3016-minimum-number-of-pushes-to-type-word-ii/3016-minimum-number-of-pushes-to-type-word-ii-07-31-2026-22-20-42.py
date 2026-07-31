class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26

        for c in word:
            freq[ord(c) - 97] += 1

        freq.sort(reverse = True)

        ans, push = 0, 0
        for f in freq:
            ans += f * (push // 8 + 1)
            push += 1 
        
        return ans
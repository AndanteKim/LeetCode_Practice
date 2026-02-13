class Solution:
    def longestBalanced(self, s: str) -> int:
        n, ans = len(s), 1

        for i in range(n):
            freqs = [0] * 26
            for j in range(i, n):
                freqs[ord(s[j]) - 97] += 1
                flag, freq = True, freqs[ord(s[j]) - 97]
                for k in range(26):
                    if freqs[k] != 0 and freqs[k] != freq:
                        flag = False
                        break
                if flag:
                    ans = max(ans, j - i + 1)

        return ans
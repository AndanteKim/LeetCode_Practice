class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lowercases, uppercases = [-1] * 26, [-1] * 26

        for i, c in enumerate(word):
            if ord(c) >= 97:
                o = ord(c) - 97
                lowercases[o] = i
            else:
                o = ord(c) - 65
                if uppercases[o] == -1:
                    uppercases[o] = i

        ans = 0
        for i in range(26):
            if lowercases[i] != -1 and uppercases[i] != -1 and lowercases[i] < uppercases[i]:
                ans += 1

        return ans
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        n, freq1, freq2, unmatch_cnt = len(s1), dict(), dict(), 0

        for i in range(n):
            if s1[i] != s2[i]:
                unmatch_cnt += 1
            
            if unmatch_cnt > 2:
                return False

            freq1[s1[i]] = freq1.get(s1[i], 0) + 1
            freq2[s2[i]] = freq2.get(s2[i], 0) + 1

        return freq1 == freq2

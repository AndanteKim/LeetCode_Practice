class Solution:
    def customSortString(self, order: str, s: str) -> str:
        count_s, ans = Counter(s), ""
        remainder_lexico = count_s.keys() - Counter(order).keys()
        for c in order:
            while count_s[c] > 0:
                ans += c
                count_s[c] -= 1
        
        for c in remainder_lexico:
            while count_s[c] > 0:
                ans += c
                count_s[c] -= 1
        return ans
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        if len(s) < 3:
            return 0
        
        curr, ans = 0, 0
        count, left = dict(), 0

        for right, c in enumerate(s):
            count[c] = count.get(c, 0) + 1

            while count.get('a', 0) >= 1 and count.get('b', 0) >= 1 and count.get('c', 0) >= 1:
                ans += len(s) - right
                count[s[left]] -= 1
                left += 1

        return ans
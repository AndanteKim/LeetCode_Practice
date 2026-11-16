class Solution:
    def digitSum(self, s: str, k: int) -> str:
        ans = s

        while len(ans) > k:
            nxt = ""
            for i in range(0, len(ans), k):
                curr = 0
                for j in range(i, min(len(ans), i + k)):
                    curr += ord(ans[j]) - 48
                nxt += str(curr)
            ans = nxt

        return ans
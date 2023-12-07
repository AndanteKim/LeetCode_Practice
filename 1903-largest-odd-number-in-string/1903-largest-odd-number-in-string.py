class Solution:
    def largestOddNumber(self, num: str) -> str:
        ans, i, n, curr = "", 0, len(num), ""
        
        while i < n:
            if int(num[i]) % 2:
                if curr:
                    ans += curr
                    curr = ""
                ans += num[i]
                i += 1
            else:
                j = i
                while j < n and int(num[j]) % 2 == 0:
                    curr += num[j]
                    j += 1
                i = j
        return ans
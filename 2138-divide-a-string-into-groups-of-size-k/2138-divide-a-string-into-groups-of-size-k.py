class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans, curr = [], ""

        for c in s:
            curr += c
            if len(curr) == k:
                ans.append(curr)
                curr = ""

        if curr:
            curr += fill * (k - len(curr))
            ans.append(curr)
        return ans 
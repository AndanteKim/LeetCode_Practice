class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = []    # Grouped string
        n, curr = len(s), 0     # Starting index of each group

        # Split string
        while curr < n:
            ans.append(s[curr : curr + k])
            curr += k

        # Try to fill in the last group
        ans[-1] += fill * (k - len(ans[-1]))

        return ans
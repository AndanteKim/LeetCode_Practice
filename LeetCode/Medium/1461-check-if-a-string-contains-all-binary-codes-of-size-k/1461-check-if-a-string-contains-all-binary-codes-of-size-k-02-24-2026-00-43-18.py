class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        
        ans, n = {s[:k]}, len(s)
        curr = deque(s[:k])

        for i in range(k, n):
            curr.popleft()
            curr.append(s[i])
            ans.add("".join(curr))

        return len(ans) == (1 << k)
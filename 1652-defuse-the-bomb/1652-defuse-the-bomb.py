class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        
        for i in range(n):
            curr = 0
            if k > 0:
                for di in range(1, k + 1):
                    curr += code[(i + di) % n]
            else:
                for di in range(1, abs(k) + 1):
                    curr += code[(i - di + n) % n]
            ans[i] = curr
        
        return ans
class Solution:
    def sumZero(self, n: int) -> List[int]:
        curr_left, curr_right, idx = -(n - 1), n - 1, n >> 1
        ans, left, right = [0] * n, idx if n % 2 else idx - 1, idx

        while left >= 0 or right < n:
            if left >= 0:
                ans[left] = curr_left
                left -= 1
                curr_left += 1
            
            if right < n:
                ans[right] = curr_right
                right += 1
                curr_right -= 1

        if n % 2:
            ans[idx] = 0
        return ans
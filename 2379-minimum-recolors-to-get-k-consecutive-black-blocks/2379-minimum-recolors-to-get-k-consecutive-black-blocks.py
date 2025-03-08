class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        if len(blocks) < k:
            return -1
        
        ans, n = 0, len(blocks)
        for i in range(k):
            if blocks[i] == 'W':
                ans += 1

        left, curr = 0, ans
        for right in range(k, n):
            if blocks[right] == 'W':
                curr += 1

            if blocks[left] == 'W':
                curr -= 1
            left += 1
            ans = min(ans, curr)

        return ans
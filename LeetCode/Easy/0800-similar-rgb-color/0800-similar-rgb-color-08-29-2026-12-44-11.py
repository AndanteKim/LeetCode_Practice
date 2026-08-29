class Solution:
    def similarRGB(self, color: str) -> str:
        def find_target(section: str) -> str:
            curr, min_diff = -1, 1000
            
            for i in range(16):
                curr_diff = (int(section, 16) - i * 17) ** 2
                if curr_diff < min_diff:
                    min_diff = curr_diff
                    ans = i

            return hex(ans)[-1] * 2

        ans = "#"

        for i in range(1, 6, 2):
            ans += find_target(color[i:i + 2])

        return ans
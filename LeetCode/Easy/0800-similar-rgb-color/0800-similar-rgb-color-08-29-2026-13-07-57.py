class Solution:
    def similarRGB(self, color: str) -> str:
        def find_target(section: str) -> str:
            num = int(section, 16)
            x = round(num / 17)

            return hex(x)[-1] * 2

        ans = "#"
        for i in range(1, 6, 2):
            ans += find_target(color[i : i + 2])
        
        return ans
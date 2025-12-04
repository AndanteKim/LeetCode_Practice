class Solution:
    def countCollisions(self, directions: str) -> int:
        ans, flag = 0, -1

        for c in directions:
            if c == 'L':
                if flag >= 0:
                    ans += flag + 1
                    flag = 0
            elif c == 'S':
                if flag > 0:
                    ans += flag
                flag = 0
            else:
                if flag >= 0:
                    flag += 1
                else:
                    flag = 1

        return ans
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        flatten = [elem for row in grid for elem in row]
        flatten.sort()

        median = flatten[len(flatten) // 2 - 1] if len(flatten) % 2 == 0 else flatten[len(flatten) // 2]
        ans = 0

        for elem in flatten:
            if abs(elem - median) % x != 0:
                return -1

            ans += abs(elem - median) // x 

        return ans
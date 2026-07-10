class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        rights = [i - 1 for i in range(1, n) if nums[i] - nums[i - 1] > maxDiff]
        rights.append(n - 1)

        return [
            bisect_left(rights, x) == bisect_left(rights, y) for x, y in queries
        ]
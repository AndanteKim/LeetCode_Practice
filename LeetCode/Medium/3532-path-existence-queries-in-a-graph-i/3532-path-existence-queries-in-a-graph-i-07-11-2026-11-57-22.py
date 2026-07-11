class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        tags = [0] * n

        for i in range(1, n):
            tags[i] = tags[i - 1] + (
                1 if nums[i] - nums[i - 1] > maxDiff else 0
            )

        return [tags[x] == tags[y] for x, y in queries]
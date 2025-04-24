class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        unique = set()

        for num in nums:
            unique.add(num)

        ans, n = 0, len(nums)
        for i in range(n):
            seen = dict()
            for j in range(i, n):
                seen[nums[j]] = seen.get(nums[j], 0) + 1
                if len(seen) == len(unique):
                    ans += 1

        return ans
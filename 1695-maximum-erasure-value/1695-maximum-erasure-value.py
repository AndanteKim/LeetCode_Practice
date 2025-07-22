class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        left, seen, curr, ans = 0, set(), 0, 0

        for right in range(len(nums)):
            while nums[right] in seen:
                curr -= nums[left]
                seen.remove(nums[left])
                left += 1
            
            curr += nums[right]
            seen.add(nums[right])
            ans = max(ans, curr)

        return ans
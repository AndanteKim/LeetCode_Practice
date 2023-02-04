class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        counts = defaultdict(list)
        ans = curr = 0
        left = 0
        for right in range(len(nums)):
            if counts[nums[right]] == []:
                curr += nums[right]
                counts[nums[right]].append(right)
            else:
                while (left <= counts[nums[right]][-1]):
                    curr -= nums[left]
                    left += 1
                counts[nums[right]].append(right)
                curr += nums[right]
            
            ans = max(ans, curr)
            
        return ans
class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        # Store the maximum nums values in max_reward
        min_reward, max_reward = 1, max(nums)
        n = len(nums)

        # Use binary search to find the minimum reward possible
        while min_reward < max_reward:
            mid_reward = min_reward + ((max_reward - min_reward) >> 1)
            houses_robbed, i = 0, 0

            while i < n:
                if nums[i] <= mid_reward:
                    houses_robbed += 1
                    i += 2  # Skip the next house to maintain the non-adjacent condition
                else:
                    i += 1
            
            if houses_robbed >= k:
                max_reward = mid_reward
            else:
                min_reward = mid_reward + 1

        return min_reward
class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        ans = 0

        while len(nums) > 1:
            min_sum, is_ascending = float('inf'), True
            target_idx = -1

            for i in range(len(nums) - 1):
                pair_sum = nums[i] + nums[i + 1]
                
                if nums[i] > nums[i + 1]:
                    is_ascending = False

                if pair_sum < min_sum:
                    min_sum, target_idx = pair_sum, i
            
            if is_ascending:
                break
            
            ans += 1
            nums[target_idx] = min_sum
            nums.pop(target_idx + 1)

        return ans
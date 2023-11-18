class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        # binary search
        
        def check(i: int) -> int:
            target, left, right, best = nums[i], 0, i, i
            
            while left <= right:
                mid = (left + right) >> 1
                count = i - mid + 1
                final_sum = count * target
                original_sum = prefix[i] - prefix[mid] + nums[mid]
                operations_required = final_sum - original_sum
                
                if operations_required > k:
                    left = mid + 1
                else:
                    best = mid
                    right = mid - 1
            return i - best + 1
        
        nums.sort()
        prefix = [nums[0]]
        
        for i in range(1, len(nums)):
            prefix.append(nums[i] + prefix[-1])
        
        ans = 0
        for i in range(len(nums)):
            ans = max(ans, check(i))
        
        return ans
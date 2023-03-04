class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        answer = 0
        min_pos = max_pos = left_bound = -1
        
        for i in range(len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                left_bound = i
            
            if nums[i] == minK:
                min_pos = i
            
            if nums[i] == maxK:
                max_pos = i
            
            answer += max(0, min(min_pos, max_pos) - left_bound)
        
        return answer
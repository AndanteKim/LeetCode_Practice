class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_dq, min_dq = deque(), deque()
        left, max_length = 0, 0
        
        for right in range(len(nums)):
            # Maintain the max_dq in decreasing order
            while max_dq and max_dq[-1] < nums[right]:
                max_dq.pop()
            max_dq.append(nums[right])
            
            # Maintain the min_dq in increasing order
            while min_dq and min_dq[-1] > nums[right]:
                min_dq.pop()
            min_dq.append(nums[right])
            
            # Check if the current window exceeds the limit
            while max_dq[0] - min_dq[0] > limit:
                # Remove the elements that are out of the current window
                if max_dq[0] == nums[left]:
                    max_dq.popleft()
                    
                if min_dq[0] == nums[left]:
                    min_dq.popleft()
                    
                left += 1
            
            max_length = max(max_length, right - left + 1)
            
        return max_length
        